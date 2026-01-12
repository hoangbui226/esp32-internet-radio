#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include "Audio.h"

extern Adafruit_SSD1306 display;
extern Audio audio;

extern int stationIndex;

extern int volumeLevel;
extern int lastAppliedVolume;

extern String metaTitle;

extern unsigned long lastUiMs;
extern unsigned long lastVolReadMs;

extern float potFiltered;
