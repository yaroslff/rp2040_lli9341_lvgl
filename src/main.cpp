#include <Arduino.h>
#include <FastLED.h>
#include "TFT_eSPI.h"
#include "SPI.h"

#define NUM_LEDS 1
#define DATA_PIN 23

CRGB leds[NUM_LEDS];
TFT_eSPI tft = TFT_eSPI();

void setup()
{
  pinMode(25, OUTPUT);
  pinMode(11, OUTPUT);

  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);

  digitalWrite(25, 1);
  digitalWrite(11, 1);

  tft.init();
  tft.setRotation(2);
  
  // Seed the random number generator
  randomSeed(analogRead(0));
}

void loop()
{
  // Clear the screen with a dark green color
  tft.fillScreen(TFT_BLACK);
  
  // Set the cursor to the top left corner of the display (0,0) and select font 2
  tft.setCursor(0, 0, 2);
  
  // Set the font color to be white with a black background, set text size multiplier to 1
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(1);
  
  // Print a greeting message
  tft.println("Hello World!");
  
  // Generate random hours (0-23) and minutes (0-59)
  int hours = random(0, 24);
  int minutes = random(0, 60);
  
  // Format the time string manually
  char timeString[6]; // "HH:MM" + null terminator
  sprintf(timeString, "%02d:%02d", hours, minutes);
  
  // Print the random time
  tft.setTextColor(TFT_YELLOW);
  tft.setTextFont(7);
  tft.println(timeString);
  
  // Add some other text for demonstration purposes
  tft.setTextColor(TFT_RED, TFT_BLACK);
  tft.setTextFont(4);
  tft.println("Some random time!");
  
  // Delay for a second before updating the time again
  delay(1000);
}
