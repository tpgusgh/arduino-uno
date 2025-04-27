#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 rfid(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin(); 
  rfid.PCD_Init();
  Serial.println("RC522 RFID 리더 준비 완료!");
}

void loop() {
  // 새 카드가 인식될 때까지 대기
  if ( !rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial() ) {
    return; // 카드가 없으면 돌아가기
  }

  Serial.print("카드 UID: ");
  for (byte i = 0; i < rfid.uid.size; i++) {
    Serial.print(rfid.uid.uidByte[i] < 0x10 ? "0" : ""); // 한자리수면 0 붙이기
    Serial.print(rfid.uid.uidByte[i], HEX);
  }
  Serial.println();

  // 카드가 인식되면 멈추기
  while(true) {
    // 이곳에서 멈춰버리면 루프가 더 이상 반복되지 않음
    // 추가 작업을 하고 싶다면 이 안에서 실행
  }
}
