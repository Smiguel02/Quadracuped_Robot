#include "Servo.h"

/**
 * @brief Both libraries are yet to be tested
 *
 * @param pin
 * @param PWM_Instance
 */

void initiate_servo(int pin, RP2040_PWM *PWM_Instance)
{
     PWM_Instance = new RP2040_PWM(pin, FREQUENCY, 37.5);
}

void servo_rotate(int degrees, int pin, RP2040_PWM *PWM_Instance)
{
     long T = 1 / FREQUENCY;
     long wave_form = 7.5 + degrees * 0.5555;
     long dutyCycle = wave_form / T;

     PWM_Instance->setPWM(pin, FREQUENCY, dutyCycle);
}