#include <WiFi.h>
#include "app_config.h"
#include "wifi_manager.h"

void wifi_connect_blocking(uint32_t timeout_ms) {
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  const unsigned long t0 = millis();
  while (WiFi.status() != WL_CONNECTED && (millis() - t0) < timeout_ms) {
    delay(250);
  }
}

bool wifi_is_connected() {
  return WiFi.status() == WL_CONNECTED;
}
