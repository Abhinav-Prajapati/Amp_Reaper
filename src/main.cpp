#include <Arduino.h>
#include "moter.h"
#include "Drive.h"

#include <IBusBM.h>
 
IBusBM ibus;

Moter Moter_A = Moter(2, 3, 6, 7);
OmniWheelDrive dirve = OmniWheelDrive(0.1, 0.3);

double wheels[3];

int readChannel(byte channelInput, int minLimit, int maxLimit, int defaultValue) {
  uint16_t ch = ibus.readChannel(channelInput);
  if (ch < 100) return defaultValue;
  return map(ch, 1000, 2000, minLimit, maxLimit);
}
 
// Read the channel and return a boolean value
bool readSwitch(byte channelInput, bool defaultValue) {
  int intDefaultValue = (defaultValue) ? 100 : 0;
  int ch = readChannel(channelInput, 0, 100, intDefaultValue);
  return (ch > 50);
}


void setup()
{
    Serial.begin(9600);
    ibus.begin(Serial1);
}

void loop()
{

  int value_1 = readChannel(0, -10, 10, 0);
  int value_2 = readChannel(2, -10, 10, 0);
  int value_3 = readChannel(3, -10, 10, 0);

    dirve.calculateWheelSpeeds(value_3,value_2,value_1, wheels);
    Serial.println(String(wheels[0]) + " " + String(wheels[1]) + " " + String(wheels[2]));
    delay(30);
}