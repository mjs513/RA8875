#include <Adafruit_GFX.h>

#include <SPI.h>
#include <RA8875.h>

#include <ili9488_t3_font_ComicSansMS.h>
#include "Fonts/FreeSansOblique12pt7b.h"

#define RA8875_CS 10
#define RA8875_RST 8
RA8875 tft = RA8875(RA8875_CS, RA8875_RST);

void setup() {
  Serial.begin(38400);
  long unsigned debug_start = millis ();
  while (!Serial && ((millis () - debug_start) <= 5000)) ;
  //  begin display: Choose from: RA8875_480x272, RA8875_800x480, RA8875_800x480ALT, Adafruit_480x272, Adafruit_800x480
  tft.begin(RA8875_480x272);
  
  tft.setRotation(2);
  tft.fillWindow(RA8875_BLACK);
  
  tft.setTextColor(RA8875_WHITE);
  tft.println("This is a test");
  tft.println(" of the default font");
  tft.println();
  tft.setTextColor(RA8875_WHITE, RA8875_BLUE);

  tft.setFont(ComicSansMS_12);
  tft.println("This is a test!!");
  tft.println(" of ILIxxx font ComicSansMS_12");
  tft.println();

  tft.setTextColor(RA8875_WHITE, RA8875_RED);
  tft.setFont(&FreeSansOblique12pt7b);
  tft.println("This is a test of GFX");
  tft.println(" of GFX font FreeSansOblique12pt");

  tft.setFontDefault();
  tft.setTextColor(RA8875_GREEN);
  tft.setFontScale(1);
  tft.println("This is default font:");
  tft.setFontSpacing(1);//now give 5 pix extra spacing between chars
  tft.println("ABCDEF 1 2 3 4 5 6 7");
  
}

void loop() 
{  }