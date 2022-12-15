#include "legs00.h"

/**
 * @brief Initiates servos values. [0] is +90º, [1] is -90º
 *
 */

void initiate_servos(float myServos[][3])
{

	myServos[0][0] = 12.6;
	myServos[0][1] = 2.8;
	myServos[0][2] = 0;

	myServos[1][0] = 12.4;
	myServos[1][1] = 2.6;
	myServos[1][2] = 1;

	myServos[2][0] = 12.8;
	myServos[2][1] = 2.9;
	myServos[2][2] = 2;

	myServos[3][0] = 13;
	myServos[3][1] = 3.2;
	myServos[3][2] = 3;

	myServos[4][0] = 12.3;
	myServos[4][1] = 2.5;
	myServos[4][2] = 12;

	myServos[5][0] = 12.6;
	myServos[5][1] = 2.7;
	myServos[5][2] = 13;

	myServos[6][0] = 12;
	myServos[6][1] = 2.4;
	myServos[6][2] = 14;

	myServos[7][0] = 12.9;
	myServos[7][1] = 3.2;
	myServos[7][2] = 15;
}

// void initiate_servos_pwm(int pin, RP2040_PWM *PWM_Instance)
// {
// 	PWM_Instance = new RP2040_PWM(pin, FREQUENCY, 0);
// }

void servo_rotate(int degrees, int pin, float servos[], RP2040_PWM *PWM_Instance)
{
	// float dutyCycle = map(degrees, -90, 90, servos[1], servos[0]);
	float dutyCycle = (degrees - (-90)) * (servos[0] - servos[1]) / (90 - (-90)) + servos[1];
	Serial.printf("dutyCycle: %lf\n", dutyCycle);
	PWM_Instance->setPWM(pin, FREQUENCY, dutyCycle);
}