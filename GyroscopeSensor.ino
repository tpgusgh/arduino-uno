// ✅ 준비물
// 아두이노 보드 (Uno, Nano 등)

// MPU-6050 자이로센서 모듈

// 점퍼선

// 아두이노 IDE


#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();

  if (mpu.testConnection()) {
    Serial.println("MPU6050 연결 성공!");
  } else {
    Serial.println("MPU6050 연결 실패...");
    while (1);
  }
}

void loop() {
  int16_t gx, gy, gz;

  mpu.getRotation(&gx, &gy, &gz); // 각속도 (gyro) 데이터 읽기

  Serial.print("Gyro X: "); Serial.print(gx);
  Serial.print(" | Y: "); Serial.print(gy);
  Serial.print(" | Z: "); Serial.println(gz);

  delay(200);
}
