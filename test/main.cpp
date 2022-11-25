#include <Arduino.h>
#include <RP2040_PWM.h>

#define BUTTON1 16
#define BUTTON2 17

void setup()
{
	pinMode(BUTTON1, INPUT_PULLUP);
	pinMode(BUTTON2, INPUT_PULLUP);

	Serial.begin(115200);
}

void loop()
{
	if (!digitalRead(BUTTON1))
	{
		Serial.println("Button1 pressed");
	}
	if (!digitalRead(BUTTON2))
	{
		Serial.println("Button2 pressed");
	}
	delay(50);
}
