#pragma once
#include <Adafruit_SSD1306.h>

extern unsigned long lastUiMs;
extern Adafruit_SSD1306 display;

void drawUI(const char* statusLine);