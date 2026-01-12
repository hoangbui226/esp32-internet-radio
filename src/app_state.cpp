#include "app_config.h"
#include "app_state.h"

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
Audio audio;

int stationIndex = 0;

int volumeLevel = 10;
int lastAppliedVolume = -1;

String metaTitle = "";

unsigned long lastUiMs = 0;
unsigned long lastVolReadMs = 0;

float potFiltered = 0.0f;
