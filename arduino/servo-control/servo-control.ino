// SG90 서보모터 자동 회전 (0° → 180° → 0° 반복)
// 보드: Arduino Uno
//
// 배선:
//   SG90 주황(Signal) → Arduino D9
//   SG90 빨강(VCC)    → Arduino 5V
//   SG90 갈색(GND)    → Arduino GND

#include <Servo.h>

const int SERVO_PIN = 9;

Servo servo;
int angle = 0;
int step = 1;

void setup() {
  servo.attach(SERVO_PIN);
  Serial.begin(9600);
  Serial.println("=== 서보모터 자동 회전 시작 ===");
}

void loop() {
  servo.write(angle);

  Serial.print("각도: ");
  Serial.print(angle);
  Serial.println("°");

  angle += step;

  // 0° ~ 180° 왕복
  if (angle >= 180 || angle <= 0) {
    step = -step;
  }

  delay(20);
}
