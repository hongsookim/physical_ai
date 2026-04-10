// 초음파 거리 측정 (HC-SR04)
// 보드: Arduino Uno/Nano

const int TRIG_PIN = 9;
const int ECHO_PIN = 10;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.println("=== 초음파 거리 측정 시작 ===");
}

void loop() {
  float distance = measureDistance();

  Serial.print("거리: ");
  Serial.print(distance, 1);
  Serial.println(" cm");

  delay(500);
}

float measureDistance() {
  // 트리거 신호 발사 (10μs HIGH 펄스)
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // 에코 핀에서 반사파 수신 시간 측정
  long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  // 거리 계산: 소리 속도 343m/s, 왕복이므로 /2
  // distance(cm) = duration(μs) * 0.0343 / 2
  float distance = duration * 0.0343 / 2.0;

  return distance;
}
