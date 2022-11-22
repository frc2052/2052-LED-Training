#include <FastLED.h>
#include "constants.h"

extern CRGB g_leds[];
int step = -2;
CHSV pulseColor = CHSV(0, 0, 255); //initialize to white

void pulseInit(CRGB color)
{
    pulseColor = rgb2hsv_approximate(color);
}

void pulseUpdate()
{    
    if (pulseColor.value + step > 255 || pulseColor.value + step < 10)
    {
        step = -step; //reverse direction
    }
    
    pulseColor.value = pulseColor.value + step; //change the brightness of the LED
    fill_solid(g_leds, NUM_LEDS, pulseColor);
    FastLED.show();
}