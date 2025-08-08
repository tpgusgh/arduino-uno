const int micPin = A0;      // 마이크 입력 핀
const int buzzerPin = 8;    // 부저 출력 핀
const int threshold = 600;  // 소리 감지 임계값 (값 조정 가능)

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600); // 시리얼 모니터로 마이크 값 확인 가능
}

void loop() {
  int micValue = analogRead(micPin); // 마이크 소리 크기 읽기
  Serial.println(micValue);          // 시리얼로 출력해 보기

  if (micValue > threshold) {
    digitalWrite(buzzerPin, HIGH); // 소리가 크면 부저 울림
    delay(200);
    digitalWrite(buzzerPin, LOW);
  }

  delay(100); // 짧은 딜레이
}
