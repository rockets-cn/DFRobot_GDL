/*!
 * @file UI_contal.ino
 * @brief 在屏幕上创建一个开关，文本框和滑条控件，用户可以这些控件的参数，也可以使用默认的参数
 * @n 当用户使用控件时，会在文本框显示你当前的操作
 * @n 本示例支持的主板有Arduino Uno, Leonardo, Mega2560, ESP32, ESP8266, FireBeetle-M0
 * @n 需要文本框显示时，需要点击文本框以使光标移到文本框内
 * @copyright  Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @author [fengli](li.feng@dfrobot.com)
 * @version  V1.0
 * @date  2019-12-6
 * @get from https://www.dfrobot.com
 * @url https://github.com/DFRobot/DFRobot_GDL/src/DFRpbot_UI
*/


#include "DFRobot_UI.h"
#include "Arduino.h"
#include "DFRobot_GDL.h"
#include "DFRobot_Touch.h"
/*M0*/
#if defined ARDUINO_SAM_ZERO
#define TFT_DC  7
#define TFT_CS  5
#define TFT_RST 6
#define TOUCH_CS 2
/*ESP32 and ESP8266*/
#elif defined(ESP32) || defined(ESP8266)
#define TFT_DC  D3
#define TFT_CS  D4
#define TFT_RST D5
#define TOUCH_CS D6
/*AVR系列主板*/
#else
#define TFT_DC  2
#define TFT_CS  3
#define TFT_RST 4
#define TOUCH_CS 5
#endif

/**
 * @brief Constructor  当触摸采用XPT2046芯片时，可以调用此构造函数
 * @param cs  SPI片选信号
 * @param rst  复位信号
 * @param irq  中断信号
 */
DFRobot_Touch_XPT2046 touch(/*cs=*/TOUCH_CS); 

/**
 * @brief Constructor  当屏采用硬件SPI通信，驱动IC是st7789，屏幕分辨率是240x320时，可以调用此构造函数
 * @param dc  SPI通信的命令/数据线引脚
 * @param cs  SPI通信的片选引脚
 * @param rst  屏的复位引脚
 */
DFRobot_ILI9341_240x320_HW_SPI screen(TFT_DC,TFT_CS,TFT_RST);
//DFRobot_ST7789_240x320_HW_SPI screen(/*dc=*/TFT_DC,/*cs=*/TFT_CS,/*rst=*/TFT_RST);
/*M0主板下DMA传输*/
//DFRobot_ST7789_240x240_DMA_SPI screen(/*dc=*/TFT_DC,/*cs=*/TFT_CS,/*rst=*/TFT_RST);
//DFRobot_ST7789_240x320_DMA_SPI screen(/*dc=*/TFT_DC,/*cs=*/TFT_CS,/*rst=*/TFT_RST);


/**
 * @brief 构造函数
 * @param gdl 屏幕对象
 * @param touch 触摸对象
 * @param width 屏幕的宽度.
 * @param height 屏幕的高度.
 */
DFRobot_UI ui(&screen, &touch,/*width=*/240,/*height=*/320);


DFRobot_UI::sObject_t * tb;


//滑条控件的回调函数
void changeColor(void* value) {
	uint16_t *value1 = (uint16_t*)value;
  char str[3];
  char text[30] = {0};
  itoa((int)*value1, str, 10);
  memcpy(text, "slider's value is ", 19);
  memcpy(text + 19, "\0", 1);
  memcpy(text + 18, str, 3);
ui.setText(tb,text);
}

//开关控件的回调函数
void swCallBack(void *state) {
  uint8_t *state1 = (uint8_t*)state;
  Serial.println(*state1);
  if (*state1 == 0) {
    ui.setText(tb,"you have turn off the Switch!");
  }
  else {
    ui.setText(tb,"you have turn on the Switch!");
  }
}
void setup()
{

  Serial.begin(9600);
  ui.begin();
  // 设置UI的主题，有两种主题可供选择 1.CLASSIC ，2.MODERN。
  ui.setTheme(DFRobot_UI::MODERN);


  //初始化滑条控件，对滑条的参数进行初始化赋值
  DFRobot_UI::sObject_t *slider = ui.creatSlider();
  slider->setCallBack(slider,changeColor);
  //在指定位置绘制滑条
  ui.draw(slider,/*x = */40,/*y = */120);
  
  DFRobot_UI::sObject_t *sw = ui.creatSwitch();
  sw->setCallBack(sw,swCallBack);
  //在指定位置绘制开关
  ui.draw(sw,/*x = */40,/*y = */200,/*width=*/55,/*height=*/20);
  
  //创建一个文本框控件
  tb = ui.creatText();
  //在屏幕上创建一个文本框控件，根据自定义或初始化的参数绘制文本框
  ui.draw(tb);
}


void loop()
{
  ui.refresh();
}