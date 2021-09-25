/*
   Juniper Robotics - Grow Tower Controller LEDs
*/

#include "FastLED.h"                               //include libraries for extra functionality
#include <string.h>

//define constants
#define NUM_LEDS_PER_STRIP 10                      //number of LEDs on grow light

CRGB ringLEDS[NUM_LEDS_PER_STRIP];                 //configure LED strip with number of LEDs

//define varaibles
unsigned long lastTime = 0, currentTime = 0;
unsigned int ledTime = 1000, index = 0, i, ratio = 3;

//setup function to configure LEDs
void setup() {
  FastLED.addLeds<NEOPIXEL, 2>(ringLEDS, NUM_LEDS_PER_STRIP);
  FastLED.setBrightness(20);                       //brightness ranges from 0-255
  FastLED.clear();                                 //turn all LEDs to off
  FastLED.show();                                  //update LED values (actually turns off now)
}

void loop () {
  currentTime = millis();                          //store current millis timer value into currentTime variable
  if (currentTime - lastTime >= ledTime) {
    lastTime = currentTime;                        //store current time as last time ran
    for (i = 0; i < NUM_LEDS_PER_STRIP; i++) {     //select each individual LED on strip
      if ((i + index) % ratio == 0) {              //this makes the color move down the strip
        ringLEDS[i] = CRGB::Red; //color 1         //set LED color
      }
      else {
        ringLEDS[i] = CRGB::Blue; //color 2        //set LED color
      }
      FastLED.show();                              //update LED value
    }
    index++;
    if (index >= NUM_LEDS_PER_STRIP)  //if the position moved past the last LED on the strip
    {
      index = 0;                      //reset index position to the beginning
    }
  }
}
