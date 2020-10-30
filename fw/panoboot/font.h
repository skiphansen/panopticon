uint8_t font_8x8[] = {
  0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,

  0xFF, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0xFF, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xFF,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xFF,

  0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F,
  0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0,
  0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,

  0x00, 0x78, 0x4A, 0x4A, 0x7A, 0x02, 0x1E, 0x00,
  0x00, 0x00, 0x00, 0x1E, 0x12, 0x12, 0x1E, 0x00,
  0x00, 0x7E, 0x42, 0x42, 0x42, 0x42, 0x7E, 0x00,
  0x00, 0x7E, 0x7E, 0x7E, 0x7E, 0x7E, 0x7E, 0x00,

  0x92, 0x49, 0x92, 0x49, 0x92, 0x49, 0x92, 0x49,
  0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55,
  0xAA, 0xFF, 0x55, 0xFF, 0xAA, 0xFF, 0x55, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};


uint8_t spr_8x8[] = {
// 16x8 Space Invader x 4 frames
  0, 0, 0, 0,15, 0, 0, 0,
  0, 0, 0, 0, 0,15, 0, 0,
  0, 0, 0, 0,15,15,15,15,
  0, 0, 0,15,15, 0,15,15,
  0, 0,15,15,15,15,15,15,
  0, 0,15, 0,15,15,15,15,
  0, 0,15, 0,15, 0, 0, 0,
  0, 0, 0, 0, 0,15,15, 0,

  0, 0,15, 0, 0, 0, 0, 0,
  0,15, 0, 0, 0, 0, 0, 0,
 15,15,15, 0, 0, 0, 0, 0,
 15,15,15,15, 0, 0, 0, 0,
 15,15,15,15,15, 0, 0, 0,
 15,15,15, 0,15, 0, 0, 0,
  0, 0,15, 0,15, 0, 0, 0,
 15,15, 0, 0, 0, 0, 0, 0,

  0, 0, 0, 0,15, 0, 0, 0,
  0, 0, 0, 0, 0,15, 0, 0,
  0, 0,15, 0,15,15,15,15,
  0, 0,15,15,15, 0,15,15,
  0, 0,15,15,15,15,15,15,
  0, 0,15, 0,15,15,15,15,
  0, 0, 0, 0,15, 0, 0, 0,
  0, 0, 0, 0, 0,15,15, 0,

  0, 0,15, 0, 0, 0, 0, 0,
  0,15, 0, 0, 0, 0, 0, 0,
 15,15,15, 0,15, 0, 0, 0,
 15,15,15,15,15, 0, 0, 0,
 15,15,15,15,15, 0, 0, 0,
 15,15,15, 0,15, 0, 0, 0,
  0, 0,15, 0, 0, 0, 0, 0,
 15,15, 0, 0, 0, 0, 0, 0,

  0, 0, 0, 0,15, 0, 0, 0,
  0, 0,15, 0, 0,15, 0, 0,
  0, 0,15, 0,15,15,15,15,
  0, 0,15,15,15, 0,15,15,
  0, 0, 0,15,15,15,15,15,
  0, 0, 0, 0,15,15,15,15,
  0, 0, 0, 0,15, 0, 0, 0,
  0, 0, 0, 0, 0,15,15, 0,

  0, 0,15, 0, 0, 0, 0, 0,
  0,15, 0, 0,15, 0, 0, 0,
 15,15,15, 0,15, 0, 0, 0,
 15,15,15,15,15, 0, 0, 0,
 15,15,15,15, 0, 0, 0, 0,
 15,15,15, 0, 0, 0, 0, 0,
  0, 0,15, 0, 0, 0, 0, 0,
 15,15, 0, 0, 0, 0, 0, 0,

  0, 0, 0, 0,15, 0, 0, 0,
  0, 0, 0, 0, 0,15, 0, 0,
  0, 0,15, 0,15,15,15,15,
  0, 0,15,15,15, 0,15,15,
  0, 0,15,15,15,15,15,15,
  0, 0,15, 0,15,15,15,15,
  0, 0, 0, 0,15, 0, 0, 0,
  0, 0, 0, 0, 0,15,15, 0,

  0, 0,15, 0, 0, 0, 0, 0,
  0,15, 0, 0, 0, 0, 0, 0,
 15,15,15, 0,15, 0, 0, 0,
 15,15,15,15,15, 0, 0, 0,
 15,15,15,15,15, 0, 0, 0,
 15,15,15, 0,15, 0, 0, 0,
  0, 0,15, 0, 0, 0, 0, 0,
 15,15, 0, 0, 0, 0, 0, 0,

// 16x8 Shelter
  0, 0, 0,15,15, 0, 0,15,
  0, 0, 0,15,15, 0, 0,15,
  0,15,15,15,15,15,15,15,
  0,15,15,15,15,15,15,15,
  0,15,15,15,15,15,15,15,
  0,15,15,15,15,15,15,15,
  0,15,15,15,15, 0, 0, 0,
  0,15,15, 0, 0, 0, 0, 0,

 15, 0, 0,15,15, 0, 0, 0,
 15, 0, 0,15,15, 0, 0, 0,
 15,15,15,15,15,15,15, 0,
 15,15,15,15,15,15,15, 0,
 15,15,15,15,15,15,15, 0,
 15,15,15,15,15,15,15, 0,
  0, 0, 0,15,15,15,15, 0,
  0, 0, 0, 0, 0,15,15, 0,

// 8x8 Player

  0, 0, 0,15, 0, 0, 0, 0,
  0, 0, 0,15, 0, 0, 0, 0,
  0, 0,15,15,15, 0, 0, 0,
  0, 0,15,15,15, 0, 0, 0,
  0,15,15,15,15,15, 0, 0,
  0,15,15,15,15,15, 0, 0,
 15,15,15,15,15,15,15, 0,
 15, 0, 0,15, 0, 0,15, 0,

// 8x8 Bullet

  0, 0, 0,15, 0, 0, 0, 0,
  0, 0, 0,11, 0, 0, 0, 0,
  0, 0, 0,11, 0, 0, 0, 0,
  0, 0, 0, 9, 0, 0, 0, 0,
  0, 0, 0, 9, 0, 0, 0, 0,
  0, 0, 0, 1, 0, 0, 0, 0,
  0, 0, 0, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,

// 16x16 Mouse Cursor
  7, 0, 0, 0, 0, 0, 0, 0,
  7, 7, 0, 0, 0, 0, 0, 0,
  7, 8, 7, 0, 0, 0, 0, 0,
  7, 8, 8, 7, 0, 0, 0, 0,
  7, 8, 8, 8, 7, 0, 0, 0,
  7, 8, 8, 8, 8, 7, 0, 0,
  7, 8, 8, 8, 8, 8, 7, 0,
  7, 8, 8, 8, 8, 8, 8, 7,

  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,

  7, 8, 8, 8, 8, 8, 8, 8,
  7, 8, 8, 8, 7, 7, 7, 7,
  7, 8, 8, 7, 0, 0, 0, 0,
  7, 8, 7, 0, 0, 0, 0, 0,
  7, 7, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,

  7, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
};