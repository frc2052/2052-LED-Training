#include <Arduino.h>  //include library
#include <FastLED.h> //include library
#include "constants.h"
#include "pulse.h"
#include "rainbow.h"
#include "pinReader.h"

CRGB g_leds[NUM_LEDS]; //create our LED array object for all our LEDs
Rainbow rb = Rainbow();
Pulse pulseGold = Pulse();
Pulse pulseRed = Pulse();
Pulse pulseGreen = Pulse();
Pulse pulseBlue = Pulse();
Pulse pulsePurple = Pulse();
PinReader reader = PinReader();

int mode = 0;

void setup() {
  FastLED.addLeds<CHIP_SET, DATA_PIN, COLOR_ORDER>(g_leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(VOLTS, MAX_AMPS);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear();
  FastLED.show();
  pulseGold.init(CRGB::Gold);
  pulseRed.init(CRGB::Red);
  pulseGreen.init(CRGB::Green);
  pulseBlue.init(CRGB::Blue);
  pulsePurple.init(CRGB::Purple);
  rb.init(100);
  reader.init();

  Serial.begin(9600);
  Serial.println("Setup Complete");
}

void loop() {
  mode = reader.read();
  Serial.println(mode);
  //Serial.print("Pin 9 ");
  //Serial.println(digitalRead(9));

  switch (mode) {
    case 1:
      pulseGold.update();
      break;
    case 2:
      pulseRed.update();
      break;
    case 3:
      pulseGreen.update();
      break;
    case 4:
      pulseBlue.update();
      break;
    case 5:
      pulsePurple.update();
      break;
    default:
      rb.update();
  }
}