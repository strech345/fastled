#include <Arduino.h>
#include <FastLED.h>
#define NUM_LEDS 3

int brightness = 200;
int ledI = 0;

CRGBArray<NUM_LEDS> leds;

void setup() { 
  FastLED.addLeds<WS2812,2>(leds, NUM_LEDS);
  Serial.begin(115200);
  //FastLED.setBrightness(10);
}

void loop(){ 
  if(++brightness == 255){
    brightness = 200;
    if (++ledI >= NUM_LEDS) {
      ledI = 0;
    }
  }
  Serial.println(brightness);
    leds[0].setRGB(0,0,255);

    leds[1].setRGB(0,255,0);
    
    leds[2].setRGB(255,0, 0);
    if (ledI != 0){
      leds[0].fadeLightBy(200);
    }
    if (ledI != 1){
      leds[1].fadeLightBy(200);
    }
    if (ledI != 2){
      leds[2].fadeLightBy(200);
    }
    leds[ledI].fadeLightBy(brightness);
    delay(100);

FastLED.show();
}