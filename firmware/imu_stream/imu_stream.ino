/*
  imu_stream.ino
  烧录到 XIAO nRF52840 Sense 上，让它不停地把加速度计读数
  通过串口打印出来，格式是 "x,y,z"，配合 webapp.html 使用。

  跟第六课用的是同一个固件，不用重新设计，
  这节课的"计步"逻辑全部写在网页JS里，板子只负责传数据。

  需要先装好 Seeed_Arduino_LSM6DS3 库（Arduino IDE 里
  Sketch > Include Library > Add .ZIP Library... 装官方那个库）。
*/

#include "LSM6DS3.h"
#include "Wire.h"

LSM6DS3 myIMU(I2C_MODE, 0x6A);

void setup() {
  Serial.begin(115200);
  while (!Serial) { ; }

  if (myIMU.begin() != 0) {
    Serial.println("IMU_ERROR");
  } else {
    Serial.println("IMU_READY");
  }
}

void loop() {
  float x = myIMU.readFloatAccelX();
  float y = myIMU.readFloatAccelY();
  float z = myIMU.readFloatAccelZ();

  Serial.print(x, 4);
  Serial.print(",");
  Serial.print(y, 4);
  Serial.print(",");
  Serial.println(z, 4);

  delay(20); // 大约 50 次/秒
}
