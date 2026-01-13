#pragma once
#include <Arduino.h>

bool oled_ui_init();
void oled_ui_draw_status(const char* statusLine);
void oled_ui_draw_wifi(bool wifiState);
void oled_ui_draw_info();