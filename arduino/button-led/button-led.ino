// 버튼을 누르면 LED가 0.1초 간격으로 10번 깜박임
// 보드: Arduino Uno/Nano
//
// 구성:
//   - LED: D11 (외부 저항 220Ω)
//   - 버튼: D7 (INPUT 모드)

int buttonPin = 7;
int ledPin = 11;
int lastButtonState = LOW;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  // 버튼이 눌리는 순간(LOW → HIGH)에만 깜박임 시작
  if (buttonState == HIGH && lastButtonState == LOW) {
    for (int i = 0; i < 10; i++) {
      digitalWrite(ledPin, HIGH);
      delay(100);
      digitalWrite(ledPin, LOW);
      delay(100);
    }
  }

  lastButtonState = buttonState;
}
