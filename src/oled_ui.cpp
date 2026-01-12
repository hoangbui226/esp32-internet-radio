#include <WiFi.h>
#include "app_config.h"
#include "app_state.h"
#include "radio_station.h"
#include "oled_ui.h"

bool oled_ui_init() {
  Wire.begin(I2C_SDA, I2C_SCL);

  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    return false;
  }

  display.clearDisplay();
  display.display();
  return true;
}

void oled_ui_draw(const char* statusLine) {
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("WiFi: ");
  display.println((WiFi.status() == WL_CONNECTED) ? "OK" : "DOWN");

  display.setCursor(0, 10);
  display.print("IP: ");
  display.println(WiFi.localIP());

  display.setCursor(0, 22);
  display.print("Station: ");
  display.println(station_get(stationIndex).name);

  display.setCursor(0, 34);
  display.print("Vol: ");
  display.print(volumeLevel);
  display.print("/");
  display.println(VOL_MAX);

  display.setCursor(0, 46);
  display.println(statusLine ? statusLine : "");

  display.setCursor(0, 56);
  if (metaTitle.length() > 0) {
    String t = metaTitle;
    if (t.length() > 21) t = t.substring(0, 21) + "...";
    display.print(t);
  } else {
    display.print("No metadata");
  }

  display.display();
}
