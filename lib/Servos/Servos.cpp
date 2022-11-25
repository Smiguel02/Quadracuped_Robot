#include "Servos.h"

/**
 * @brief Initiates servos values. [0] is +90º, [1] is -90º
 *
 */

void initiate_servos()
{
	long servos[8][3];

	servos[0][0] = 12.6;
	servos[0][1] = 2.8;
	servos[0][2] = 0;

	servos[1][0] = 12.4;
	servos[1][1] = 2.6;
	servos[1][2] = 1;

	servos[2][0] = 12.8;
	servos[2][1] = 2.9;
	servos[2][2] = 2;

	servos[3][0] = 13;
	servos[3][1] = 3.2;
	servos[3][2] = 3;

	servos[4][0] = 12.3;
	servos[4][1] = 2.5;
	servos[4][2] = 12;

	servos[5][0] = 12.6;
	servos[5][1] = 2.7;
	servos[5][2] = 13;

	servos[6][0] = 12;
	servos[6][1] = 2.4;
	servos[6][2] = 14;

	servos[7][0] = 12.9;
	servos[7][1] = 3.2;
	servos[7][2] = 15;
}

void initiate_servos_pwm(int pin, RP2040_PWM *PWM_Instance)
{
	PWM_Instance = new RP2040_PWM(pin, FREQUENCY, 0);
}

void servo_rotate(int degrees, int pin, RP2040_PWM *PWM_Instance)
{
	long dutyCycle = map(degrees, -90, 90, servos[pin][1], servos[pin][0]);
	PWM_Instance->setPWM(pin, FREQUENCY, dutyCycle);
}