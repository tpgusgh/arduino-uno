const int pulsePin = A0;    // Pulse Sensor 입력 핀
int signal;                 // 센서에서 읽은 값
int threshold = 550;        // 심박 인식 임계값 (센서에 따라 조정 필요)

void setup() {
  Serial.begin(9600);
  pinMode(pulsePin, INPUT);
  Serial.println("Pulse Sensor 시작!");
}

void loop() {
  signal = analogRead(pulsePin);
  Serial.println(signal);   // 아날로그 값 출력 (0 ~ 1023)

  if (signal > threshold) {
    Serial.println("♥ 심박 감지됨!");
    delay(200);             // 중복 감지를 방지하는 간단한 딜레이
  }

  delay(20);                // 측정 간격 조절
}
