#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "app_config.h"
#include "volume_updater.h"

static unsigned long lastUiMs = 0;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void drawUI(const char* statusLine) {
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
  display.println(stations[stationIndex].name);

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
