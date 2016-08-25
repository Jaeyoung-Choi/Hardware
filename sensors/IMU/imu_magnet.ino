
#include "BMI160Gen.h"
// include the SPI library:
#include "ss_spi.h"
#include <SPI.h>

BMI160GenClass BMI160;
const int select_pin = PA_3;

void setup() {
  Serial.begin(115200); // initialize Serial communication
  Serial.println("Start!");

  // initialize device
  BMI160.begin(select_pin);
}

void loop() {

  int gx, gy, gz;         // raw gyro values

  // read raw gyro measurements from device
  BMI160.readGyro(gx, gy, gz);

  // display tab-separated gyro x/y/z values
  Serial.print("g:\t");
  Serial.print(gx);
  Serial.print("\t");
  Serial.print(gy);
  Serial.print("\t");
  Serial.print(gz);
  Serial.println();

  int ax, ay, az;         // raw gyro values

  // read raw gyro measurements from device
  BMI160.readAccelerometer(ax, ay, az);

  // display tab-separated gyro x/y/z values
  Serial.print("a:\t");
  Serial.print(ax);
  Serial.print("\t");
  Serial.print(ay);
  Serial.print("\t");
  Serial.print(az);
  Serial.println();

  int mx, my, mz;         // raw gyro values

  // read raw gyro measurements from device
  BMI160.readMag(mx, my, mz);

  // display tab-separated gyro x/y/z values
  Serial.print("m:\t");
  Serial.print(mx);
  Serial.print("\t");
  Serial.print(my);
  Serial.print("\t");
  Serial.print(mz);
  Serial.println();

  int hall = 0;         // raw gyro values

  // read raw gyro measurements from device
  BMI160.readHall(hall);
  // display tab-separated gyro x/y/z values
  Serial.print("h:\t");
  Serial.print(hall);
  Serial.println();

  unsigned int temp = 0;         // raw gyro values

  // read raw gyro measurements from device
  temp = BMI160.readTemperature();
  // display tab-separated gyro x/y/z values
  Serial.print("t:\t");
  Serial.print((temp-1000)*0.01);
  Serial.println("C");

  delay(100);
}


