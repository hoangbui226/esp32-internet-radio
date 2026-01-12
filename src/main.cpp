#include <Arduino.h>
#include "app_config.h"
#include "app_state.h"

#include "wifi_manager.h"
#include "oled_ui.h"
#include "media_player.h"
#include "volume_updater.h"
#include "radio_station.h"

static bool prevNextState = true;
static bool prevPrevState = true;

static void buttons_init() {
  pinMode(BTN_NEXT, INPUT_PULLUP);
  pinMode(BTN_PREV, INPUT_PULLUP);
}

static void adc_init() {
  analogReadResolution(12);
  analogSetAttenuation(ADC_11db);
}

void setup() {
  Serial.begin(115200);

  buttons_init();
  adc_init();

  if (!oled_ui_init()) {
    Serial.println("OLED init failed");
  }

  oled_ui_draw("Booting...");

  wifi_connect_blocking(15000);
  oled_ui_draw(wifi_is_connected() ? "WiFi connected" : "WiFi failed");

  media_player_init();

  volume_init_from_pot();

  media_player_start_station(stationIndex);
  oled_ui_draw("Connecting...");
}

void loop() {
  media_player_loop();
  volume_update_from_pot();

  // Buttons edge detect
  const bool nextState = digitalRead(BTN_NEXT);
  const bool prevState = digitalRead(BTN_PREV);

  if (prevNextState == HIGH && nextState == LOW) {
    media_player_start_station(stationIndex + 1);
    oled_ui_draw("Connecting...");
  }
  if (prevPrevState == HIGH && prevState == LOW) {
    media_player_start_station(stationIndex - 1);
    oled_ui_draw("Connecting...");
  }

  prevNextState = nextState;
  prevPrevState = prevState;

  // UI refresh
  if (millis() - lastUiMs > UI_REFRESH_MS) {
    lastUiMs = millis();
    oled_ui_draw("Playing...");
  }
}
