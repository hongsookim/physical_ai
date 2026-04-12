// I2C 주소 스캐너
#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("=== I2C 스캐너 시작 ===");
}

void loop() {
  int count = 0;
  for (byte addr = 1; addr < 127; addr++) {
    Wire.beginTransmission(addr);
    if (Wire.endTransmission() == 0) {
      Serial.print("I2C 장치 발견: 0x");
      if (addr < 16) Serial.print("0");
      Serial.println(addr, HEX);
      count++;
    }
  }

  if (count == 0) {
    Serial.println("I2C 장치를 찾을 수 없습니다.");
  } else {
    Serial.print("총 ");
    Serial.print(count);
    Serial.println("개 장치 발견");
  }

  delay(3000);
}
