#include <Arduino.h>
#include "OneButton.h"
#include "LED.h"

#define bottom_pin 9
#define FASTLED_INTERNAL

void bottom_pressed();
void bottom_longpressed();
void fill(uint32_t color,CRGB *leds);

u8_t led_kind = 0;
u8_t led_kind_num = 8;

u8_t led_special_kind = 0;
u8_t led_special_kind_num = 2;

CRGB leds[NUM_LEDS];

OneButton btn = OneButton(
  bottom_pin,  // Input pin for the button
  true,        // Button is active LOW
  false         // Enable internal pull-up resistor
);


void setup() {
    pinMode(LED_PIN,OUTPUT);
    FastLED.addLeds<WS2812,LED_PIN,GRB>(leds,NUM_LEDS);
    FastLED.clear();
    FastLED.setBrightness(bright);
    FastLED.showColor(0xffffff);
    FastLED.show();
        //attachInterrupt(digitalPinToInterrupt(9),bottom_pressed,RISING);
    btn.attachClick(bottom_pressed);//短按切换状态
    btn.attachLongPressStart(bottom_longpressed);//长按切换特殊状态
}

void loop() {
    btn.tick();
        //leds.clear();
        //LED_Ranbow(leds);
        //leds.show();
        
}

/// @brief 按钮按下led_kind会加1，还会清理led数据(可用性未知)
void bottom_pressed(){
    led_kind++;
    FastLED.clear();FastLED.show();
    led_kind = led_kind % led_kind_num;
        if (led_kind==0){fill(0xff0000,leds);FastLED.show(); }
        if (led_kind==1){fill(0x00ff00,leds);FastLED.show();}
        if (led_kind==2){fill(0x0000ff,leds);FastLED.show();}
        if (led_kind==3){Wota_mode_fire(leds);}
        if (led_kind==4){Wota_mode_sakura(leds);}
        if (led_kind==5){Wota_mode_miku(leds);}
        if (led_kind==6){Wota_mode_sakulaX3(leds);}
        if (led_kind==7){Wota_mode_frost(leds);}
}

void bottom_longpressed(){
    led_special_kind++;
    FastLED.clear();
    led_special_kind = led_special_kind % led_special_kind_num;
        if (led_special_kind==0){fill(0xffffff,leds);FastLED.show();}
        if (led_special_kind==1){fill(0x39c5bb,leds);FastLED.show();}
}

/// @brief 颜色填充函数
/// @param color 6位16进制的颜色HEX值
/// @param leds led灯的实例
void fill(uint32_t color,CRGB *leds){
    for (int i = 0; i < NUM_LEDS; i++)
    {
        leds[i] = CRGB(color);
    }
    FastLED.show();
}
