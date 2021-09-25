/*
   Juniper Robotics - Grow Tower Controller LEDs
*/

#include "FastLED.h"
#include <string.h>

//define constants
#define NUM_LEDS_PER_STRIP 10  //number of LEDs on grow light

CRGB ringLEDS[NUM_LEDS_PER_STRIP];  //configure LED strip with number of LEDs

//define varaibles
unsigned long ledMillis = 0, currentMillis = 0;
unsigned int ledTime = 1000, index = 0, i, ratio=3;

void setup() {
  FastLED.addLeds<NEOPIXEL, 2>(ringLEDS, NUM_LEDS_PER_STRIP);
  FastLED.setBrightness(20);   //brightness ranges from 0-255
  FastLED.clear();
  FastLED.show();
}

void loop () {
  currentMillis = millis();
  if (currentMillis - ledMillis >= ledTime) {
    ledMillis = currentMillis;
    updateLEDs();
  }
}

void updateLEDs() {
  for (i = 0; i < NUM_LEDS_PER_STRIP; i++) {
    if ((i + index) % ratio == 0) {
      ringLEDS[i] = CRGB::Red; //color 1
    }
    else {
      ringLEDS[i] = CRGB::Blue; //color 2
    }
    FastLED.show();
  }
  index++;
  if (index >= NUM_LEDS_PER_STRIP)  //if the index position is larger than the number of LEDs on the strip
  {
    index = 0;  //reset index position
  }
}
