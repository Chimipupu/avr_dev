#include "common.hpp"
#include "drv_timer.hpp"
#include "drv_7segled.hpp"
#include "mfs.hpp"

uint32_t g_cnt = 0;
static uint8_t s_7segled_dat_buf[SEVEN_SEGMENT_LED_NUN] = { 0x03, 0x02, 0x01, 0x00 };

void beep_buzzer(uint8_t cnt)
{
    digitalWrite(MFS_BUZZER_PIN, LOW);
    delay(30);
    digitalWrite(MFS_BUZZER_PIN, HIGH);
}

void setup()
{
    // GPIO初期化
    pinMode(MFS_BUTTON_S1_PIN, INPUT);
    pinMode(MFS_BUTTON_S2_PIN, INPUT);
    pinMode(MFS_BUTTON_S3_PIN, INPUT);
    pinMode(MFS_BUZZER_PIN, OUTPUT);
    pinMode(MFS_LED_1_PIN, OUTPUT);
    pinMode(MFS_LED_2_PIN, OUTPUT);
    pinMode(MFS_LED_3_PIN, OUTPUT);
    pinMode(MFS_LED_4_PIN, OUTPUT);
    pinMode(MFS_74HC595_SDI_PIN, OUTPUT);
    pinMode(MFS_74HC595_CLK_PIN, OUTPUT);
    pinMode(MFS_74HC595_LATCH_PIN, OUTPUT);

    // タイマー初期化
    drv_timer_init();

    // UART初期化
    Serial.begin(115200);

    // MFSのLEDとブザーを停止
    digitalWrite(MFS_LED_1_PIN, HIGH);
    digitalWrite(MFS_LED_2_PIN, HIGH);
    digitalWrite(MFS_LED_3_PIN, HIGH);
    digitalWrite(MFS_LED_4_PIN, HIGH);
    digitalWrite(MFS_BUZZER_PIN, HIGH);
}

void loop()
{
    uint32_t start_time = millis();

    drv_num_to_7seg(g_cnt, &s_7segled_dat_buf[0]);

    uint32_t end_time = millis();
    Serial.print(F("処理時間 : "));
    Serial.print(end_time - start_time);
    Serial.print(F(" ms\n"));
}