// DC 모터 핀 설정
const int IN1 = 8;
const int IN2 = 9;
const int ENA = 10; // PWM 속도 제어 핀

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  // 모터 정방향 회전
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // 속도 제어 (0~255)
  analogWrite(ENA, 200); // 약 78% 속도
}

void loop() {
  // 모터 계속 회전
}
