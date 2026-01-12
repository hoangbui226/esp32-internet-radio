#pragma once
#include <Arduino.h>

/* ===================== WIFI CONFIG ===================== */
static const char* WIFI_SSID = "YOUR_WIFI";
static const char* WIFI_PASS = "YOUR_PASS";

/* OLED pins */
static const int I2C_SDA = 21;
static const int I2C_SCL = 22;

/* MAX98357A */
static const int I2S_BCLK = 27;
static const int I2S_LRC  = 26;
static const int I2S_DOUT = 25;   // ESP32 -> DIN on MAX98357A

/* Buttons pins */
static const int BTN_NEXT = 32;
static const int BTN_PREV = 33;

/* Potentiometer */
static const int POT_PIN  = 34;

/* OLED display */

#define SCREEN_WIDTH  128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1

static const uint8_t OLED_ADDR = 0x3C;

/* Volume range */
static const int VOL_MIN = 0;
static const int VOL_MAX = 21;

/* UI sampling periods */
static const uint32_t UI_REFRESH_MS = 200;
static const uint32_t POT_READ_MS   = 30;
