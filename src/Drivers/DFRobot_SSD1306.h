#ifndef __DFROBOT_SSD1306_H
#define __DFROBOT_SSD1306_H

#define DF_ST7735S_WIDTH  

static const uint8_t PROGMEM DFRobot_SSD1306_initCmd[] = {
  //cmd delayFlag/argsNum argsValue 延时（超过255）延时/255
0x01, 0xAE, 0,   //display off
0x01, 0x20, 0,//Set Memory Addressing Mode	
0x01, 0x10, 0,//00,Horizontal Addressing Mode;01,Vertical Addressing Mode;10,Page Addressing Mode (RESET);11,Invalid
0x01, 0xb0, 0,//Set Page Start Address for Page Addressing Mode,0-7
0x01, 0x00, 0,//---set low column address
0x01, 0x10, 0,//---set high column address
0x01, 0xc8, 0,//Set COM Output Scan Direction
0x01, 0x40, 0,//--set start line address
0x01, 0x81, 0,//--set contrast control register
0x01, 0x7f, 0,
0x01, 0xa1, 0,//--set segment re-map 0 to 127
0x01, 0xa6, 0,//--set normal display
0x01, 0xa8, 0,//--set multiplex ratio(1 to 64)
0x01, 0x3F, 0,//
0x01, 0xa4, 0,//0xa4,Output follows RAM content;0xa5,Output ignores RAM content
0x01, 0xd3, 0,//-set display offset
0x01, 0x00, 0,//-not offset
0x01, 0xd5, 0,//--set display clock divide ratio/oscillator frequency
0x01, 0xf0, 0,//--set divide ratio
0x01, 0xd9, 0,//--set pre-charge period
0x01, 0x22, 0, //
0x01, 0xda, 0,//--set com pins hardware configuration
0x01, 0x12, 0,
0x01, 0xdb, 0,//--set vcomh
0x01, 0x20, 0,//0x20,0.77xVcc
0x01, 0x8d, 0,//--set DC-DC enable
0x01, 0x14, 0,//
0x01, 0xaf, 0,//--turn on oled panel 
0x00
};
#endif