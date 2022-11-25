#include <Arduino.h>
#include <RP2040_PWM.h>
#include <Servos.h>

#define BUTTON1 16
#define BUTTON2 17

void setup()
{
    Serial.begin(115200);
    pinMode(BUTTON1, INPUT_PULLUP);
    pinMode(BUTTON2, INPUT_PULLUP);
}

void loop()
{
}
