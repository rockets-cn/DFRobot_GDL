static const uint8_t PROGMEM DFRobot_ST7789_initCmd[] = {
0x01, 0x11, 0x80, 100,
0x01, 0xf0, 1, 0xc3,
0x01, 0xf0, 1, 0x96,
0x01, 0x36, 1, 0x48,
0x01, 0x3A, 1, 0x55,
0x01, 0xB4, 1, 0x01,
0x01, 0xB7, 1, 0xc6,
0x01, 0xe8, 8, 0x40,0x8a, 0x00, 0x00, 0x29, 0x19, 0xa5, 0x33,
0x01, 0xc2, 1, 0xa7,
0x01, 0xc5, 1, 0x3c,
0x01, 0xe0, 14,0xf0, 0x00, 0x02, 0x0a, 0x0d, 0x1d, 0x35, 0x55, 0x45, 0x3c, 0x17, 0x17, 0x18, 0x1b,
0x01, 0xe1, 14,0xf0, 0x00, 0x02, 0x07, 0x06, 0x04, 0x2e, 0x44, 0x45, 0x0b, 0x17, 0x16, 0x18, 0x1b,
0x01, 0xf0, 1, 0x3c,
0x01, 0xf0, 0x81, 100,0x69,
0x01, 0x29, 0,
0x00
};
