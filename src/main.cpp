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
  analogReadResolution(12); // 12 bit resolution
  analogSetAttenuation(ADC_11db);
}

void setup() {
  Serial.begin(115200);
  delay(5000);

  buttons_init();
  adc_init();

  if (!oled_ui_init()) {
    Serial.println("OLED init failed");
  }

  oled_ui_draw_status("Booting...");

  // Connect to WiFi
  Serial.println("Connecting to WiFi...");
  bool isWifiConnected = wifi_connect_blocking(15000); // Wifi connect, 15ms timeout
  Serial.println(isWifiConnected ? "WiFi connected" : "WiFi connection failed");
  Serial.println("IP: ");
  Serial.println(WiFi.localIP());
  oled_ui_draw_wifi(isWifiConnected);

  media_player_init();
  volume_init();

  media_player_start_station(stationIndex);
  oled_ui_draw_status("Connecting...");
}

void loop() {
  media_player_loop();
  volume_update();

  // Buttons edge detect
  const bool nextState = digitalRead(BTN_NEXT);
  const bool prevState = digitalRead(BTN_PREV);

  if (prevNextState == HIGH && nextState == LOW) {
    media_player_start_station(stationIndex + 1);
    oled_ui_draw_status("Connecting...");
  }
  if (prevPrevState == HIGH && prevState == LOW) {
    media_player_start_station(stationIndex - 1);
    oled_ui_draw_status("Connecting...");
  }

  prevNextState = nextState;
  prevPrevState = prevState;

  // UI refresh
  if (millis() - lastUiMs > UI_REFRESH_MS) {
    lastUiMs = millis();
    oled_ui_draw_info();
  }
}
