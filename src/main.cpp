#include <Arduino.h>
#include "moter.h"

Moter Moter_A = Moter(2, 3, 6, 7);

void setup()
{
    Serial.begin(9600);
}
void moveBot(int vel_X, int vel_Y, int rotation_Z)
{
}

void loop()
{
    Moter_A.setPWM(100);
    delay(1000);
    Moter_A.setPWM(-100);
    delay(1000);

}