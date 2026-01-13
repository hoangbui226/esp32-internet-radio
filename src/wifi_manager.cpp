#include <WiFi.h>
#include "app_config.h"
#include "wifi_manager.h"

bool wifi_connect_blocking(uint32_t timeout_ms) {
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  const unsigned long t0 = millis();
  while (WiFi.status() != WL_CONNECTED && (millis() - t0) < timeout_ms) {
    delay(200);
  }
  return WiFi.status() == WL_CONNECTED;
}
