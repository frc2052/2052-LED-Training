#include <Arduino.h>  //include library
#include <FastLED.h> //include library
#include "constants.h"
#include "pulse.h"
#include "rainbow.h"

CRGB g_leds[NUM_LEDS]; //create our LED array object for all our LEDs
Rainbow rb = Rainbow();
Pulse gold = Pulse();
Pulse red = Pulse();
Pulse green = Pulse();
Pulse blue = Pulse();
Pulse purple = Pulse();
int mode = 0;

void setup() {
  FastLED.addLeds<CHIP_SET, DATA_PIN, COLOR_ORDER>(g_leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(VOLTS, MAX_AMPS);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear();
  FastLED.show();
  gold.init(CRGB::Gold);
  red.init(CRGB::Red);
  green.init(CRGB::Green);
  blue.init(CRGB::Blue);
  purple.init(CRGB::Purple);
  rb.init(100);

  mode = 5;
}

void loop() {
  switch (mode) {
    case 1:
      gold.update();
      break;
    case 2:
      red.update();
      break;
    case 3:
      green.update();
      break;
    case 4:
      blue.update();
      break;
    case 5:
      purple.update();
      break;
    default:
      rb.update();
  }
}