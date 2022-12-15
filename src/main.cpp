#include <legs00.h>

#define BUTTON1 16
#define BUTTON2 17
#define PinToPWM1 0
#define PinToPWM2 1
#define PinToPWM3 2
#define PinToPWM4 3
#define PinToPWM5 12
#define PinToPWM6 13
#define PinToPWM7 14
#define PinToPWM8 15

float servos[8][3];
RP2040_PWM *PWM_Instance[4];

int i = 0;

void initiate_servos_pwm(int pin)
{
    PWM_Instance[0] = new RP2040_PWM(pin, FREQUENCY, 0);
}

void setup()
{
    initiate_servos(servos);
    for (i = 0; i < 8; i++)
    {
        // initiate_servos_pwm(servos[i][2]);
        PWM_Instance[(int)i / 2] = new RP2040_PWM(servos[i][2], FREQUENCY, 0);
    }
    i = 0;
    Serial.begin(115200);
    // Serial.printf("pin: %f, 90º: %f, -90º: %f\n", servos[0][2], servos[0][0], servos[0][1]);
}

void loop()
{

    // i = 0;
    // Serial.print("Rotate to 90 degrees, ");
    // servo_rotate(45, (int)servos[1][2], servos[1], PWM_Instance[(int)i]);
    // delay(1000);
    // Serial.print("Rotate to 0 degrees, ");
    // servo_rotate(0, (int)servos[1][2], servos[1], PWM_Instance[(int)i]);
    // delay(1000);
    // Serial.print("Rotate to -90 degrees, ");
    // servo_rotate(-45, (int)servos[1][2], servos[1], PWM_Instance[(int)i]);
    // delay(1000);

    servo_rotate(0, (int)servos[i][2], servos[i], PWM_Instance[(int)i / 2]);
    delay(1000);

    i++;
    if (i > 7)
    {
        i = 0;
    }
}