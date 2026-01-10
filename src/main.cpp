#include <WiFi.h>
#include <Wire.h>


void setup() {
  Serial.begin(115200);

  pinMode(BTN_NEXT, INPUT_PULLUP);
  pinMode(BTN_PREV, INPUT_PULLUP);

  // ADC config (helps stability on many ESP32 boards)
  analogReadResolution(12);            // 0..4095
  analogSetAttenuation(ADC_11db);      // better range up to ~3.3V

  Wire.begin(I2C_SDA, I2C_SCL);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED init failed");
  } else {
    display.clearDisplay();
    display.display();
  }

  drawUI("Booting...");
  connectWiFi();
  drawUI((WiFi.status() == WL_CONNECTED) ? "WiFi connected" : "WiFi failed");

  // Audio init
  audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);

  // Initialize volume from pot immediately
  potFiltered = analogRead(POT_PIN);
  updateVolumeFromPot();

  startStation(stationIndex);
}

bool prevNextState = true;
bool prevPrevState = true;

void loop() {
  audio.loop();              // must be called frequently
  updateVolumeFromPot();     // pot -> volume

  // Buttons edge-detect
  bool nextState = digitalRead(BTN_NEXT);
  bool prevState = digitalRead(BTN_PREV);

  if (prevNextState == HIGH && nextState == LOW) {
    startStation(stationIndex + 1);
  }
  if (prevPrevState == HIGH && prevState == LOW) {
    startStation(stationIndex - 1);
  }

  prevNextState = nextState;
  prevPrevState = prevState;

  // UI refresh
  if (millis() - lastUiMs > 200) {
    lastUiMs = millis();
    drawUI("Playing...");
  }
}
