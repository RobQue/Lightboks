#include <FastLED.h>

#define LED_PIN     16
#define NUM_LEDS    48
#define BRIGHTNESS  100
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 100

byte PixelBUFFER[72]; // 8 x 6 neopixels

//CRGBArray<NUM_LEDS> strip;

void fastLedSetup() 
{
    //delay( 300 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);  //.setCorrection( TypicalLEDStrip ); // no need for correction
    FastLED.setBrightness(  BRIGHTNESS );
    FastLED.show();
}
void neoPixelsUpdate()
{
  for(int i=0; i< 24 ; i++) //sizeof(PixelBUFFER)/3
  {
  leds[i*2] = CRGB(  PixelBUFFER[i*3],   PixelBUFFER[i*3 + 1], PixelBUFFER[i*3 + 2] );
  //strip.setPixelColor(i*2, strip.Color(  50,   0, 0) );
  leds[i*2+1] = CRGB(  0,   0, 0 );
  }
  //FastLED.delay(33);
  FastLED.show();
}

void turnOffLeds()
{
  for(int i = 0; i< 144; i++)
  {
    LedData +=  char(0);
  }
  LedData.getBytes((unsigned char*)leds, NUM_LEDS * 3);
  LedData = "";
  FastLED.show();
}
