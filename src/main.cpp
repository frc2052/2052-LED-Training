#include <Arduino.h>
#include <FastLED.h>
#define NUM_LEDS 255 //how many LEDs are in your strip/panel
#define DATA_PIN 3 //signal wire is connected to this pin on arduino
#define COLOR_ORDER GRB //surprisingly, many LED strips don't use the color order Red,Green,Blue
#define CHIP_SET WS2812B //KnightKrawler uses WS2812B Leds, but there are many other options
#define BRIGHTNESS 255 //255 is maximum brightness, lower this value to limit brightness
#define VOLTS 5 //All WS2812B LED strips are 5v
#define MAX_AMPS 2500 //this value is in milliamps, our power converter allows for 3 amp at 5v. Choose a value at or bellow 3000 milliamps

CRGB leds[NUM_LEDS]; //create our LED array object for all our LEDs


void setup() {
  FastLED.addLeds<CHIP_SET, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(VOLTS, MAX_AMPS);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear();
  FastLED.show();
}

void loop() {
  leds[0] = CRGB(255,0,0);
  leds[1] = CRGB::Green;
  leds[2] = CRGB::Blue;
  FastLED.show();
  delay(1000);
  FastLED.clear();
  FastLED.show();  
  delay(1000);
}