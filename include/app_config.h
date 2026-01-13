#pragma once
#include <Arduino.h>

/* ===================== WIFI CONFIG ===================== */
static const char* WIFI_SSID = "DNA-WLAN-2D0F62";
static const char* WIFI_PASS = "58803233326";

/* OLED pins */
static const int I2C_SDA = 18;
static const int I2C_SCL = 5;

/* MAX98357A */
static const int I2S_BCLK = 2;
static const int I2S_LRC  = 15;
static const int I2S_DOUT = 4;

/* Buttons pins */
static const int BTN_NEXT = 19;
static const int BTN_PREV = 21;

/* Potentiometer */
static const int POT_PIN  = 34;

/* OLED display */

#define SCREEN_WIDTH  128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1

static const uint8_t OLED_ADDR = 0x3C;

/* Volume range */
static const int VOL_MIN = 0;
static const int VOL_MAX = 100;

/* UI sampling periods */
static const uint32_t UI_REFRESH_MS = 200;
static const uint32_t POT_READ_MS   = 30; // Potentiometer read interval
