#include <Arduino.h>
#include <Wire.h>

/**
 * Miguel's Pico works but LED has been burnt because of good soldering :)
 * @brief
 *
 */

const int MPU_ADDR = 0x68;

int16_t ax, ay, az;
int16_t gx, gy, gz;
int16_t temp;

#define LED_BUILTIN 25
pin_size_t sda = 0;
pin_size_t scl = 1;

void setup()
{

  // bool setSDA(sda);
  // bool setSCL(scl);

  Wire.begin();
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);

  pinMode(LED_BUILTIN, OUTPUT);
  // Start the serial port with 115200 baudrate
  Serial.begin(115200);
}

void loop()
{
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 6 * 2, true);

  ax = Wire.read() << 8 | Wire.read();
  ay = Wire.read() << 8 | Wire.read();
  az = Wire.read() << 8 | Wire.read();

  gx = Wire.read() << 8 | Wire.read();
  gy = Wire.read() << 8 | Wire.read();
  gz = Wire.read() << 8 | Wire.read();

  // temp = Wire.read() << 8 | Wire.read();

  Serial.print("ax: ");
  Serial.print(ax);
  Serial.print("ay: ");
  Serial.print(ay);
  Serial.print("az: ");
  Serial.print(az);
  Serial.print("gx: ");
  Serial.print(gx);
  Serial.print("gy: ");
  Serial.print(gy);
  Serial.print("gz: ");
  Serial.print(gz);
  Serial.println();

  delay(1000);
}