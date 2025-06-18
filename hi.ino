#include <Servo.h>

const int ldrPin = 34;  // 조도 센서 핀
const int servoPin = 5; // 서보 핀
int lightThreshold = 500;
bool notified = false;

Servo myservo;

void setup() {
  Serial.begin(9600);        // UART 통신
  myservo.attach(servoPin);
}

void loop() {
  int light = analogRead(ldrPin);

  // 조도 감지 시 메시지 전송
  if (light > lightThreshold && !notified) {
    Serial.println("빛 감지됨");
    notified = true;
  } else if (light <= lightThreshold) {
    notified = false;
  }

  // 수신 명령 처리
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();
    if (cmd == "open") {
      myservo.write(90);
    } else if (cmd == "close") {
      myservo.write(0);
    }
  }

  delay(500);
}
