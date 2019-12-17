#include "DFRobot_UI.h"
#include "Arduino.h"
#include "DFRobot_GDL.h"
#include "DFRobot_Touch.h"

#define RST 42
#define WR 41
#define RD 40
#define CS 38
#define RS 39

#define d0 22
#define d1 23
#define d2 24
#define d3 25
#define d4 26
#define d5 27
#define d6 28
#define d7 29
#define d8 37
#define d9 36
#define d10 35
#define d11 34
#define d12 33
#define d13 32
#define d14 31
#define d15 30

DFRobot_ILI9488_480x320 screen(CS, RS, WR, RD, d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15/*,BL,RST*/);
DFRobot_UI ui(320, 480);
DFRobot_Touch_GT911 gt911;
sTableview_t tv;
void scan(uint16_t * pos) {
  gt911.getPoint1(&pos[0], &pos[1]);
  gt911.getPoint2(&pos[2], &pos[3]);
  gt911.getPoint3(&pos[4], &pos[5]);
  gt911.getPoint4(&pos[6], &pos[7]);
  gt911.getPoint5(&pos[8], &pos[9]);
}
void fillRect(uint16_t x1, uint16_t y1, uint16_t width , uint16_t height, uint16_t color) {
  screen.fillRect(x1, y1, width, height, color);
}

void tvCallback(uint8_t highLightPage) {
  
  if(highLightPage == 1){
    ui.drawString(100, 200,"this is tab1", 0xf0f,0xff,2,1);
    }
  if(highLightPage == 2){
    ui.drawString(100, 200,"this is tab2", 0xf0f,0xff,2,1);
    }
  if(highLightPage == 3){
    ui.drawString(100, 200,"this is tab3", 0xf0f,0xff,2,1);
    }
  
  
}

void setup()
{

  Serial.begin(9600);
  gt911.begin();

  screen.begin();
  ui.setDrawFunction(fillRect);
  ui.setTouchFunction(scan);
  ui.setTheme(THEME1);
  ui.begin();
  tv.numPage = 3;
  tv.callback = tvCallback;
  memcpy(tv.text[0].text, "Tab 1", 5);
  memcpy(tv.text[1].text, "Tab 2", 5);
  memcpy(tv.text[2].text, "Tab 3", 5);
  ui.creatTableview(&tv);
}


void loop()
{
  
  uint16_t pos_x = 0, pos_y = 0 ;
  gt911.getPoint1(&pos_x, &pos_y);
  ui.refreshTableview(&tv,pos_x,pos_y);

   
}