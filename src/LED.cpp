#include "LED.h"

void LED_Ranbow(CRGB *leds)
{
   /*    for(long firstPixelHue = 0; firstPixelHue < 3*65536; firstPixelHue += 256)
     {
        for(int i=0; i<leds.numPixels(); i++) {
            long pixelHue = firstPixelHue + (i * 65536L / leds.numPixels());
            leds.setPixelColor(i, leds.gamma32(leds.ColorHSV(pixelHue)));
            }
        delay(9);
        leds.show();
     }*/ 
}

void Wota_mode_fire(CRGB *leds){
    for (int i = 0; i < 19; i++)
    {
        leds[i]=CRGB(255,i*14,0);
        leds[35-i]=CRGB(255,i*14,0);
        FastLED.show();
        vTaskDelay(13/portTICK_PERIOD_MS);
    }
}

void Wota_mode_sakura(CRGB *leds){
    for (int i = 0; i < 19; i++)
    {
        leds[i]=CRGB(255-i*14,0,255);
        leds[35-i]=CRGB(255-i*14,0,255);
        FastLED.show();
        vTaskDelay(13/portTICK_PERIOD_MS);
    }
}

void Wota_mode_miku(CRGB *leds){
    for (int i = 0; i < 14; i++)
    {
        //leds[i]=CRGB(57,197,187);
        //leds[35-i]=CRGB(57,197,187);
        leds[i]=CRGB(0,255,0);
        leds[35-i]=CRGB(0,255,0);
        FastLED.show();
        vTaskDelay(13/portTICK_PERIOD_MS);
    }
    for (int i = 14; i < 19; i++)
    {
        leds[i]=CRGB(255,255,255);
        leds[35-i]=CRGB(255,255,255);
        FastLED.show();
        vTaskDelay(13/portTICK_PERIOD_MS);
    }
}

void Wota_mode_sakulaX3(CRGB *leds){
    for (int i = 0; i < 6; i++)
    {
        leds[i]=CRGB(255,255,0);
        leds[35-i]=CRGB(255,255,0);
        FastLED.show();
        vTaskDelay(13/portTICK_PERIOD_MS);
    }
    for (int i = 6; i < 12; i++)
    {
        leds[i]=CRGB(255,0,0);
        leds[35-i]=CRGB(255,0,0);
        FastLED.show();
        vTaskDelay(13/portTICK_PERIOD_MS);
    }
    for (int i = 12; i < 19; i++)
    {
        leds[i]=CRGB(255,0,255);
        leds[35-i]=CRGB(255,0,255);
        FastLED.show();
        vTaskDelay(13/portTICK_PERIOD_MS);
    }
}

void Wota_mode_frost(CRGB *leds){
    for (int i = 0; i < 19; i++)
    {
        leds[i]=CRGB((int)pow(i,1.91),(int)pow(i,1.91),255);
        leds[35-i]=CRGB((int)pow(i,1.91),(int)pow(i,1.91),255);
        FastLED.show();
        vTaskDelay(13/portTICK_PERIOD_MS);
    }
}
