# Physical AI

클로드 코드 기반 피지컬 AI 프로젝트 모음.
아두이노 제어부터 로봇 제어까지 다양한 하드웨어 프로젝트를 관리한다.

## 폴더 구조

```
physical_ai/
├── arduino/          # 아두이노 기본 프로젝트 (LED, 버튼, 통신 등)
├── sensors/          # 센서 프로젝트 (초음파, IR, IMU, 온습도 등)
├── actuators/        # 액추에이터 프로젝트 (서보, DC모터, 스테퍼 등)
├── robotics/         # 로봇 제어 프로젝트 (라인트레이서, 로봇팔 등)
├── shared/           # 공유 리소스
│   ├── libraries/    # 커스텀 아두이노 라이브러리
│   └── schematics/   # 회로도 및 배선도
├── tools/            # 빌드/업로드 스크립트, 유틸리티
└── docs/             # 프로젝트 문서
```

## 환경

- **CLI**: arduino-cli 1.4.1
- **보드**: Arduino Uno (arduino:avr:uno)
- **코어**: arduino:avr 1.8.7

## 빠른 시작

```bash
# 보드 연결 확인
arduino-cli board list

# 프로젝트 컴파일 (예: 초음파 센서)
arduino-cli compile --fqbn arduino:avr:uno sensors/ultrasonic-distance

# 업로드
arduino-cli upload -p /dev/cu.usbmodem* --fqbn arduino:avr:uno sensors/ultrasonic-distance

# 시리얼 모니터
arduino-cli monitor -p /dev/cu.usbmodem* --config baudrate=9600
```

## 프로젝트 목록

| 프로젝트 | 경로 | 상태 |
|---------|------|------|
| 초음파 거리 측정 | `sensors/ultrasonic-distance` | 완료 |
