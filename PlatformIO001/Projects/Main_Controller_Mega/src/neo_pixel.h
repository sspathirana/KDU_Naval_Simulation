/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-neopixel-led-strip
 */

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>  // Required for 16 MHz Adafruit Trinket
#endif

#define PIN_NEO_PIXEL 6  // Arduino pin that connects to NeoPixel
#define NUM_PIXELS 405    // The number of LEDs (pixels) on NeoPixel

#define DELAY_INTERVAL 250  // 250ms pause between each pixel

Adafruit_NeoPixel NeoPixel(NUM_PIXELS, PIN_NEO_PIXEL, NEO_GRB + NEO_KHZ800);
char neo[405];
int pixel = 0;
void setupNeo() {
  NeoPixel.begin();  // INITIALIZE NeoPixel strip object (REQUIRED)
}

void neoPattern() {
  //neo[1]='G';
  for (pixel = 0; pixel < NUM_PIXELS; pixel++) {
    if(neo[pixel]=='R')NeoPixel.setPixelColor(pixel, NeoPixel.Color(255,0,0));
    else if(neo[pixel]=='G')NeoPixel.setPixelColor(pixel, NeoPixel.Color(0,255,0));
    else if(neo[pixel]=='B')NeoPixel.setPixelColor(pixel, NeoPixel.Color(0,0,255));
    else if(neo[pixel]=='Y')NeoPixel.setPixelColor(pixel, NeoPixel.Color(255,255,0));
    else NeoPixel.setPixelColor(pixel, NeoPixel.Color(0,0,0));
  }           // for each pixel

  NeoPixel.show();  // send the updated pixel colors to the NeoPixel hardware.
  delay(20);      // on time
  
  // turn off all pixels for one seconds
 // NeoPixel.clear();
 // NeoPixel.show();  // send the updated pixel colors to the NeoPixel hardware.
  //delay(2000);      // off time
}
