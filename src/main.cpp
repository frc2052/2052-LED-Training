#include <Arduino.h>  //include library
#include <FastLED.h> //include library
#include "constants.h"
#include "pulse.h"

CRGB g_leds[NUM_LEDS]; //create our LED array object for all our LEDs

void setup() {
  FastLED.addLeds<CHIP_SET, DATA_PIN, COLOR_ORDER>(g_leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(VOLTS, MAX_AMPS);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear();
  FastLED.show();
  pulseInit(CRGB::Gold);
}

void loop() {
  pulseUpdate();
}