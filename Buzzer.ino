int buzzerPin = 8;

// 도레미파솔라시도 주파수 (Hz)
int notes[] = {262, 294, 330, 349, 392, 440, 494, 523};

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < 8; i++) {
    tone(buzzerPin, notes[i]);  // 음 재생
    delay(500);                 // 0.5초 동안 유지
    noTone(buzzerPin);          // 소리 끔
    delay(100);                 // 약간의 간격
  }

  delay(2000); // 한 번 연주 후 잠시 멈춤
}
