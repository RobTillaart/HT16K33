//
//    FILE: demo_displayInt.ino
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.0
// PURPOSE: demo
//     URL: http://www.adafruit.com/products/1002
//     URL: https://github.com/RobTillaart/HT16K33

#include "HT16K33.h"

HT16K33 seg(0x70);

void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);

  seg.begin();
  Wire.setClock(100000);
  seg.displayOn();
  seg.brightness(2);
  seg.displayClear();
  seg.blink(0);
}

void loop()
{
  Serial.print("INT TEST 1:\t");
  for (int16_t counter = -200; counter < 1001; counter += 7)
  {
    seg.displayInt(counter);
    delay(100);
  }
  Serial.println();
  delay(1000);


  seg.suppressLeadingZeroPlaces(0);

  Serial.print("INT TEST 2:\t");
  for (int16_t counter = -200; counter < 1001; counter += 7)
  {
    seg.displayInt(counter);
    delay(100);
  }
  Serial.println();
  delay(1000);

  seg.suppressLeadingZeroPlaces(3);

}

// -- END OF FILE --
