#include <Arduino.h>
#include <stdio.h>
#include <RP2040_PWM.h>

#define FREQUENCY 50

/**
 * @brief
 *
 *
 * This library rotates our servos to our desired destination. PWM needs to be: 2.5ms to 12.5 ms -> -90 to 90 degrees
 *
 * Possibly will add time feature where it waits for it to rotate before performing any feature
 *
 */

// long myServos[8][3];

// void initiate_servos_pwm(int pin, RP2040_PWM *PWM_Instance);
void servo_rotate(int degrees, int pin, float servos[], RP2040_PWM *PWM_Instance);
void initiate_servos(float myServos[][3]);