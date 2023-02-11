#ifndef MOTER_H
#define MOTER_H

#include <Arduino.h>

class Moter
{
private:
    int _EN_1;
    int _EN_2;
    int _PWM_1;
    int _PWM_2;

public:
    Moter(int EN_1, int EN_2, int PWM_1, int PWM_2);
    void setPWM(int pwm_value);
    void stopMoter();
    void moterBreak();
};

Moter::Moter(int EN_1, int EN_2, int PWM_1, int PWM_2)
{
    /** Driver code for BTS790...  */

     _EN_1 = EN_1;
     _EN_2 = EN_2;
     _PWM_1 = PWM_1;
     _PWM_2 = PWM_2;

    pinMode(_EN_1, OUTPUT);
    pinMode(_EN_2, OUTPUT);

    pinMode(_PWM_1, OUTPUT);
    pinMode(_PWM_2, OUTPUT);

    digitalWrite(_EN_1, HIGH);
    digitalWrite(_EN_2, HIGH);
    // Serial.println("a");
}
void Moter::setPWM(int pwm_value)
{
    if (pwm_value > 0)
    {
        analogWrite(_PWM_1, 0); // Stop the other direction
        analogWrite(_PWM_2, pwm_value);
    // Serial.println("b");
    }
    else if (pwm_value < 0)
    {
        analogWrite(_PWM_2, 0);
        analogWrite(_PWM_1, -(pwm_value)); // Remove the negetive sign
    // Serial.println("c");
    }
    else{
        //If pwm is 0 turn on all low
        analogWrite(_PWM_1,0);
        analogWrite(_PWM_2,0);
    }
}
#endif
