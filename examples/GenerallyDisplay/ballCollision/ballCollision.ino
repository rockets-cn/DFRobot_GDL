/*!
 * @file ballCollision.ino
 * @brief 演示小球在屏幕中运动碰撞的动画效果 
 * @n 本示例支持的主板有Arduino Uno, Leonardo, Mega2560, FireBeetle-ESP32, FireBeetle-ESP8266, FireBeetle-M0
 * @copyright	Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @author [LuoYufeng](yufeng.luo@dfrobot.com)
 * @version  V0.1
 * @date  2020-01-07
 * @url https://github.com/DFRobot/DFRobot_GDL
 */

#include "DFRobot_GDL.h"
/*M0*/
#if defined ARDUINO_SAM_ZERO
#define TFT_DC  7
#define TFT_CS  5
#define TFT_RST 6
/*ESP32 and ESP8266*/
#elif defined(ESP32) || defined(ESP8266)
#define TFT_DC  D3
#define TFT_CS  D4
#define TFT_RST D5
/*AVR系列主板*/
#else
#define TFT_DC  2
#define TFT_CS  3
#define TFT_RST 4
#endif

/**
 * @brief Constructor  硬件SPI通信的构造函数
 * @param dc  SPI通信的命令/数据线引脚
 * @param cs  SPI通信的片选引脚
 * @param rst  屏的复位引脚
 */
DFRobot_ST7789_240x240_HW_SPI screen(/*dc=*/TFT_DC,/*cs=*/TFT_CS,/*rst=*/TFT_RST);
//DFRobot_ST7789_240x320_HW_SPI screen(/*dc=*/TFT_DC,/*cs=*/TFT_CS,/*rst=*/TFT_RST);
/*M0主板下DMA传输*/
//DFRobot_ST7789_240x240_DMA_SPI screen(/*dc=*/TFT_DC,/*cs=*/TFT_CS,/*rst=*/TFT_RST);
//DFRobot_ST7789_240x320_DMA_SPI screen(/*dc=*/TFT_DC,/*cs=*/TFT_CS,/*rst=*/TFT_RST);

/*
 *可供用户选择的宏定义颜色
 *COLOR_RGB565_BLACK   COLOR_RGB565_NAVY    COLOR_RGB565_DGREEN   COLOR_RGB565_DCYAN 
 *COLOR_RGB565_MAROON  COLOR_RGB565_PURPLE  COLOR_RGB565_OLIVE    COLOR_RGB565_LGRAY     
 *COLOR_RGB565_DGRAY   COLOR_RGB565_BLUE    COLOR_RGB565_GREEN    COLOR_RGB565_CYAN  
 *COLOR_RGB565_RED     COLOR_RGB565_MAGENTA COLOR_RGB565_YELLOW   COLOR_RGB565_ORANGE           
 *COLOR_RGB565_WHITE   
 */

int xx0 = 39;int yy0 = 99;int xx1 = 199;int yy1 = 29;int xx2 = 99;int yy2 = 59;
int xx3 = 5;int yy3 = 5;int xx4 = 5;int yy4 = 5;int xx5 = 5;int yy5 = 5;
uint16_t color1 = COLOR_RGB565_YELLOW;
uint16_t color2 = COLOR_RGB565_RED;
uint16_t color3 = COLOR_RGB565_BLUE;
void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);
    screen.begin();
    /*
     *@brief 清屏
     *@param c 屏幕颜色
     */
    screen.fillScreen(COLOR_RGB565_BLACK);
    //画实心圆形1
    screen.fillCircle(xx0,yy0,10,color1);
    //画实心圆形2
    screen.fillCircle(xx1,yy1,10,color2);
    //画实心圆形3
    screen.fillCircle(xx2,yy2,10,color3);
}

void loop() {
    screen.fillCircle(xx0,yy0,10,COLOR_RGB565_BLACK);
    screen.fillCircle(xx1,yy1,10,COLOR_RGB565_BLACK);
    screen.fillCircle(xx2,yy2,10,COLOR_RGB565_BLACK);
    int r1 = (yy0-yy1)*(yy0-yy1) + (xx0-xx1)*(xx0-xx1);
    int r2 = (yy0-yy2)*(yy0-yy2) + (xx0-xx2)*(xx0-xx2);
    int r3 = (yy2-yy1)*(yy2-yy1) + (xx2-xx1)*(xx2-xx1);
    if(r1 <= 400){
        int t = 0;
        if(fabs(yy0-yy1)<fabs(xx0-xx1)){
            t = xx3;xx3 = xx4;xx4 =t;
        }
        else if(fabs(yy0-yy1)>fabs(xx0-xx1)){
            t = yy3;yy3 = yy4;yy4 =t;
        }
        else{
            t = yy3;yy3 = yy4;yy4 =t;
            t = xx3;xx3 = xx4;xx4 =t;
        }
    }
    if(r2 <= 400){
        int t;
        if(fabs(yy0-yy2)<fabs(xx0-xx2)){
            t = xx3;xx3 = xx5;xx5 =t;
        }
        else if(fabs(yy0-yy2)>fabs(xx0-xx2)){
            t = yy3;yy3 = yy5;yy5 =t;
        }
        else{
            t = yy3;yy3 = yy5;yy5 =t;
            t = xx3;xx3 = xx5;xx5 =t;
        }
    }
    if(r3 <= 400){
        int t;
        if(fabs(yy2-yy1)<fabs(xx2-xx1)){
            t = xx5;xx5 = xx4;xx4 =t;
        }
        else if(fabs(yy2-yy1)>fabs(xx2-xx1)){
            t = yy5;yy5 = yy4;yy4 =t;
        }
        else{
            t = yy5;yy5 = yy4;yy4 =t;
            t = xx5;xx5 = xx4;xx4 =t;
        }
    }
    if(yy0<=9)
        yy3 = 5;
    else if(yy0>=(screen.height()-10))
        yy3 = -5;
    if(xx0<=9)
        xx3 = 5;
    else if(xx0>=(screen.width()-10))
        xx3 = -5;
    if(yy1<=9)
        yy4 = 5;
    else if(yy1>=(screen.height()-10))
        yy4 = -5;
    if(xx1<=9)
        xx4 = 5;
    else if(xx1>=(screen.width()-10))
        xx4 = -5;
    if(yy2<=9)
        yy5 = 5;
    else if(yy2>=(screen.height()-10))
        yy5 = -5;
    if(xx2<=9)
        xx5 = 5;
    else if(xx2>=(screen.width()-10))
        xx5 = -5;
    yy0 += yy3;xx0 += xx3;
    yy1 += yy4;xx1 += xx4;
    yy2 += yy5;xx2 += xx5;
    
    screen.fillCircle(xx0,yy0,10,color1);
    screen.fillCircle(xx1,yy1,10,color2);
    screen.fillCircle(xx2,yy2,10,color3);
    delay(100);
}
