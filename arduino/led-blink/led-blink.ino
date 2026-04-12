// 모스부호 JIHO 프로그램
// 보드: Arduino Uno/Nano
// D8 핀에 연결된 LED로 "JIHO" 모스부호 표시
//
// 모스부호 타이밍 (1 unit 기준):
//   DOT      = 1 unit
//   DASH     = 3 units
//   심볼 간격 = 1 unit (한 글자 내부)
//   글자 간격 = 3 units
//   단어 간격 = 7 units
//
// JIHO 모스부호:
//   J = · − − −
//   I = · ·
//   H = · · · ·
//   O = − − −

const int LED_PIN = 8;

const unsigned long UNIT = 200;  // 기본 시간 단위 (ms)
const unsigned long DOT = UNIT;
const unsigned long DASH = UNIT * 3;
const unsigned long SYMBOL_GAP = UNIT;
const unsigned long LETTER_GAP = UNIT * 3;
const unsigned long WORD_GAP = UNIT * 7;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("=== 모스부호 JIHO 시작 ===");
}

void loop() {
  Serial.println("JIHO");

  // J : · − − −
  dot(); dash(); dash(); dash();
  delay(LETTER_GAP);

  // I : · ·
  dot(); dot();
  delay(LETTER_GAP);

  // H : · · · ·
  dot(); dot(); dot(); dot();
  delay(LETTER_GAP);

  // O : − − −
  dash(); dash(); dash();

  // 단어 간격
  delay(WORD_GAP);
}

void dot() {
  digitalWrite(LED_PIN, HIGH);
  delay(DOT);
  digitalWrite(LED_PIN, LOW);
  delay(SYMBOL_GAP);
}

void dash() {
  digitalWrite(LED_PIN, HIGH);
  delay(DASH);
  digitalWrite(LED_PIN, LOW);
  delay(SYMBOL_GAP);
}
