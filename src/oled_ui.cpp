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

void oled_ui_draw_status(const char* statusLine) {
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);

  display.setCursor(30, 20);
  display.println(statusLine ? statusLine : "N/A");
  display.display();  
}

void oled_ui_draw_wifi(bool wifiState) {
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);

  if (wifiState == true)
  {
    display.setCursor(0, 18);
    display.print("WiFi: Connected !");

    display.setCursor(0, 30);
    display.print("IP: ");
    display.print(WiFi.localIP().toString());
    display.display();
    delay(10000);
  } else {
    display.setCursor(0, 18);
    display.print("WiFi: Failed !");

    display.setCursor(0, 30);
    display.print("IP: N/A");
    display.display();
    delay(1000000);
  }
}

void oled_ui_draw_info() {
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);

  display.setCursor(0, 0);
  display.print("Station: ");
  display.println(station_get(stationIndex).name);

  display.setCursor(0, 34);
  display.print("Vol: ");
  display.print(volumeLevel);
  display.print("/");
  display.println(VOL_MAX);
  
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