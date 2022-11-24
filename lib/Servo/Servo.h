#include <stdio.h>
#include <RP2040_PWM.h>
/**
 * @brief
 * This library rotates our servos to our desired destination. PWM needs to be: 2.5ms to 12.5 ms -> -90 to 90 degrees
 *
 * Possibly will add time feature where it waits for it to rotate before performing any feature
 *
 */

#define PWM_MAX 12.5
#define PWM_MIN 2.5
#define PWM_CENTER 7.5
#define FREQUENCY 50

void servo_rotate(int degrees, int pin, RP2040_PWM *PWM_Instance);

void initiate_servo(int pin, RP2040_PWM *PWM_Instance);