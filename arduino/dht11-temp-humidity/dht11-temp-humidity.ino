// DHT11 온습도 센서
// 보드: Arduino Uno
//
// 배선:
//   DHT11 VCC  → Arduino 5V
//   DHT11 GND  → Arduino GND
//   DHT11 DATA → Arduino D7 (10kΩ 풀업 저항으로 5V에 연결)

#include <DHT.h>

const int DHT_PIN = 7;
const int DHT_TYPE = DHT11;

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("=== DHT11 온습도 측정 시작 ===");
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("센서 읽기 실패!");
    delay(2000);
    return;
  }

  Serial.print("온도: ");
  Serial.print(temperature, 1);
  Serial.print(" °C  |  습도: ");
  Serial.print(humidity, 1);
  Serial.println(" %");

  delay(2000);  // DHT11은 최소 2초 간격으로 읽기
}
