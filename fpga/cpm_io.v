`timescale 1ns / 1ps

// z80pack compatible I/O 
// Copyright (C) 2019  Skip Hansen

// Z80 I/O 
// When the Z80 reads an I/O port the port address register is updated,
// the io_operation register is set to read and then the z80 is held in
// wait until the riscv write the data to the I/O read data register
// clears the I/O operaton register.

// When the Z80 writes an I/O port the port address and I/O write data 
// registers are updated, the io_operation register is set to write 
// and then the z80 is held in wait until the riscv reads the data and
// clears the I/O operaton register
// RISC V  Z80
// Adr     Adr   Usage              Read    Write      Notes
// 0       0  - Console status      Z80     RISC V      
// --      1  - Console in          Z80     ---         1
// --      1  - Console out         ---     Z80         2
// 1       10 - Drive               Both    Z80
// 2       11 - Track               Both    Z80
// 3       12 - Sector low          Both    Z80
// --      13 - Disk command        ---     Z80         2
// --      13 - Disk command        Z80     ---
// 4       14 - Disk status         Z80     RISC V      
// 5       15 - DMA Adr LSB         Both    Z80
// 6       16 - DMA Adr MSB         Both    Z80
// 7       17 - Sector high         Both    Z80
// --      xx - Other               Z80
// 8       -- - Z80 I/O Adr         RISC V  ---
// 9       -- - Z80 Out Data        RISC V  ---
// 10      -- - Z80 In Data         ---     RISC V
// 11      -- - Z80 I/O State       RISC V  ---         3

// Notes:
//  1 - Z80 held in wait until RISC V write the data to complete the Z80 I/O 
//      to the "Z80 In Data" register.
//  2 - Z80 held in wait until RISC V reads data for I/O write from the 
//      Z80 In Data register
//  3 - FSM state, written by hardware

module cpm_io(
    input wire clk,

// Z80 interface
    input wire z80_iord,
    input wire z80_iowr,
    input wire [7:0] z80adr,
    output reg [7:0] z80di,
    input wire [7:0] z80do,
    output reg z80_io_ready,

// RISC V interface
    input wire io_valid,
    input wire [7:0] rv_wdata,
    input wire [3:0] rv_adr,
    input wire rv_wstr,
    output reg [7:0] rv_rdata
    );

    reg [7:0] disk_drive;
    reg [7:0] disk_track;
    reg [7:0] disk_sector_lsb;
    reg [7:0] disk_sector_msb;
    reg [7:0] disk_dma_adr_lsb;
    reg [7:0] disk_dma_adr_msb;
    reg [7:0] disk_status;
    reg [7:0] io_port_adr;
    reg [7:0] out_port_data;
    reg [7:0] in_port_data;
    reg [1:0] io_port_status;
    reg [7:0] console_status;

    localparam IO_STAT_IDLE  = 2'd0;
    localparam IO_STAT_WRITE = 2'd1;
    localparam IO_STAT_READ  = 2'd2;
    localparam IO_STAT_READY = 2'd3;
    
    always@(posedge clk) begin
        if (io_valid)
             if (rv_wstr!= 0) begin
                case (rv_adr)
                    4'd0: console_status <= rv_wdata;
                    4'd1: disk_drive <= rv_wdata;
                    4'd2: disk_track <= rv_wdata;
                    4'd3: disk_sector_lsb <= rv_wdata;
                    4'd4: disk_status <= rv_wdata;
                    4'd5: disk_dma_adr_lsb <= rv_wdata;
                    4'd6: disk_dma_adr_msb <= rv_wdata;
                    4'd7: disk_sector_msb <= rv_wdata;
                    4'd8: io_port_adr <= rv_wdata;
                    4'd10: begin
                       // synthesis translate_off
                       $display("riscv wrote Z80 input data 0x%02x", rv_wdata);
                       // synthesis translate_on
                        in_port_data <= rv_wdata;
                        io_port_status <= IO_STAT_READY;
                    end
                endcase
             end
             else begin
                case (rv_adr)
                    4'd1: rv_rdata <= disk_drive;
                    4'd2: rv_rdata <= disk_track;
                    4'd3: rv_rdata <= disk_sector_lsb;
                    4'd4: rv_rdata <= disk_status;
                    4'd5: rv_rdata <= disk_dma_adr_lsb;
                    4'd6: rv_rdata <= disk_dma_adr_msb;
                    4'd7: rv_rdata <= disk_sector_msb;
                    4'd8: rv_rdata <= io_port_adr;
                    4'd9: begin
                        // synthesis translate_off
                        $display("riscv read Z80 output data 0x%02x", out_port_data);
                        // synthesis translate_on
                        rv_rdata <= out_port_data;
                        io_port_status <= IO_STAT_READY;
                    end
                    5'd11: rv_rdata <= {6'd0, io_port_status};
                    default: rv_rdata <= 8'd0;
                endcase
             end

         if (z80_iord) begin
             case (z80adr)
                 8'd0: z80di <= console_status;
                 8'd10: z80di <= disk_drive;
                 8'd11: z80di <= disk_track;
                 8'd12: z80di <= disk_sector_lsb;
                 8'd14: z80di <= disk_status;
                 8'd15: z80di <= disk_dma_adr_lsb;
                 8'd16: z80di <= disk_dma_adr_msb;
                 8'd17: z80di <= disk_sector_msb;
                 default: 
                     if (io_port_status == IO_STAT_IDLE) begin
                    // synthesis translate_off
                    $display("Z80 input port 0x%02x", z80adr);
                    // synthesis translate_on
                     io_port_status <= IO_STAT_READ;
                     io_port_adr <= z80adr;
                     z80di <= in_port_data;
                 end
             endcase
         end
         else if (z80_iowr) begin
             case (z80adr)
                 8'd10: disk_drive <= z80do;
                 8'd11: disk_track <= z80do;
                 8'd12: disk_sector_lsb <= z80do;
                 8'd15: disk_dma_adr_lsb <= z80do;
                 8'd16: disk_dma_adr_msb <= z80do;
                 8'd17: disk_sector_msb <= z80do;
                 default: 
                     if (io_port_status == IO_STAT_IDLE) begin
                     // synthesis translate_off
                     $display("Z80 output 0x%02x to port 0x%02x",z80do,z80adr);
                     // synthesis translate_on
                     io_port_status <= IO_STAT_WRITE;
                     io_port_adr <= z80adr;
                     out_port_data <= z80do;
                 end
             endcase
         end
         else begin
             io_port_status <= IO_STAT_IDLE;
         end

         if (io_port_status == IO_STAT_READY)
             z80_io_ready <= 1;
         else
             z80_io_ready <= 0;
    end
        
endmodule
