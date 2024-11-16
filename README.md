# AVRマイコン評価F/W開発 by ちみ
AVRマイコンの評価F/Wの個人開発リポジトリ🥳

## 開発環境
- 📍基板
  - 📍ATmega328p
    - 📍Arduino Uno Rev.3
    - 📍Arduino Nano
    - 📍Arduino pro mini
- 📍シールド : MFS(マルチファンクションシールド)

## 実装機能

- 📍S/W(アプリ)
  - ✅7セグLEDの制御処理（74HC595で制御）
    - ✅ダイナミック点灯
    - ✅数値から7セグ4桁に変換
  - ✅ボタン押し判定

- 📍H/W(ハードウェア)
  - 📍UART
    - ✅文字をシリアル出力
  - 📍タイマー⏰
    - ❌タイマー0(8bit)⏰ ... 未使用
    - ✅タイマー1(16bit)⏰ ... 1000㎳インターバル
    - ✅タイマー2(bit)⏰ ... 8.128msインターバル
  - 📍GPIO
    - ✅GPIO 3 ... ブザー
    - ✅GPIO 4 ... 74HC595 ラッチ用ピン
    - ✅GPIO 7 ... 74HC595 クロック用ピン
    - ✅GPIO 8 ... 74HC595 シリアルデータ用ピン
    - ✅GPIO 10 ... LED4
    - ✅GPIO 11 ... LED3
    - ✅GPIO 12 ... LED2
    - ✅GPIO 13 ... LED1
    - ✅GPIO 15 ... ボタン1
    - ✅GPIO 16 ... ボタン2
    - ✅GPIO 17 ... ボタン3

- 📍割込み（ISR）
  - ❌タイマー0⏰（TIMER0_COMPA_vect）
    - ❌未使用
  - ✅タイマー1⏰（TIMER1_COMPA_vect）
    - ✅1秒カウント
  - ✅タイマー2⏰（TIMER2_COMPA_vect）
    - ✅ボタン監視

## ATmega328p(MCU)

- MCU : ATmega328p
  - CPU : AVR
  - 命令長 : 8bit
  - Clock : 16MHz
  - ROM : 32KB
  - RAM : 2KB
  - EEPROM : 1KB
  - GPIO : x23
  - PWM : x6ch
  - UART : x1ch
  - SPI : x1ch
  - I2C : x1ch
  - ADC : 10bit x8ch
  - WDT : 1
  - Timer
    - 8bit : x2ch
    - 16bit : x1ch
