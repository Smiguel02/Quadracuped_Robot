#include <Arduino.h>
#include <RP2040_PWM.h>

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

RP2040_PWM *PWM_Instance;
double posicoes[3];
int i = 0;
double j = 0.1;
int atm;

void setup()
{
    Serial.begin(115200);
    pinMode(BUTTON1, INPUT_PULLUP);
    pinMode(BUTTON2, INPUT_PULLUP);

    atm = PinToPWM8;

    PWM_Instance = new RP2040_PWM(atm, 50, 0);
    posicoes[0] = 11; //+90º
    posicoes[1] = 4;  //-90º
    posicoes[2] = 7;  // 0º
}

void loop()
{
    PWM_Instance->setPWM(atm, 50, 12.7);
    delay(1000);
    PWM_Instance->setPWM(atm, 50, 3.2);
    delay(1000);
    PWM_Instance->setPWM(atm, 50, 8.2);
    delay(1000);

    // delay(200);
    // if (!digitalRead(BUTTON1))
    // {
    //     posicoes[i] += j;
    //     PWM_Instance->setPWM(atm, 50, posicoes[i]);
    //     Serial.print("Position:");
    //     Serial.println(posicoes[i]);
    // }

    // if (!digitalRead(BUTTON2))
    // {
    //     i++;
    //     j = -0.1;
    //     if (i == 2)
    //     {
    //         j = 0.1;
    //     }
    //     Serial.println(i);
    // }
}