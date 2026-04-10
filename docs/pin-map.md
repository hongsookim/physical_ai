# Arduino Uno 핀 배정표

프로젝트별 핀 사용 현황을 관리한다. 핀 충돌 방지 목적.

## 디지털 핀

| 핀 | 기능 | 프로젝트 | 비고 |
|----|------|---------|------|
| D0 | RX | - | 시리얼 통신 예약 |
| D1 | TX | - | 시리얼 통신 예약 |
| D2 | - | - | 인터럽트 가능 |
| D3 | PWM | - | 인터럽트 가능 |
| D4 | - | - | |
| D5 | PWM | - | |
| D6 | PWM | - | |
| D7 | - | - | |
| D8 | - | - | |
| D9 | TRIG | ultrasonic-distance | PWM 가능 |
| D10 | ECHO | ultrasonic-distance | PWM 가능 |
| D11 | PWM | - | SPI MOSI |
| D12 | - | - | SPI MISO |
| D13 | LED | - | 내장 LED, SPI SCK |

## 아날로그 핀

| 핀 | 프로젝트 | 비고 |
|----|---------|------|
| A0 | - | |
| A1 | - | |
| A2 | - | |
| A3 | - | |
| A4 | - | I2C SDA |
| A5 | - | I2C SCL |
