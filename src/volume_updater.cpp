#include "volume_updater.h"
#include <Arduino.h>
#include "app_config.h"
#include "Audio.h"

static const int VOL_MIN = 0;
static const int VOL_MAX = 21;

static int volumeLevel = 10;
static int lastAppliedVolume = -1;

static unsigned long lastVolReadMs = 0;

static float potFiltered = 0.0f;
/* Map & apply volume with hysteresis to avoid flicker */
void updateVolumeFromPot() {
  // Read pot at ~20-50 Hz (enough for volume)
  if (millis() - lastVolReadMs < 30) return;
  lastVolReadMs = millis();

  int raw = analogRead(POT_PIN); // ESP32 ADC: typically 0..4095

  // Low-pass filter (smooth)
  // alpha 0.15-0.25 is fine
  const float alpha = 0.20f;
  potFiltered = (potFiltered == 0.0f) ? raw : (alpha * raw + (1.0f - alpha) * potFiltered);

  // Map to volume range
  int mappedVol = (int)lroundf((potFiltered / 4095.0f) * (VOL_MAX - VOL_MIN) + VOL_MIN);

  // Clamp
  if (mappedVol < VOL_MIN) mappedVol = VOL_MIN;
  if (mappedVol > VOL_MAX) mappedVol = VOL_MAX;

  // Apply only if changed by at least 1 step
  if (mappedVol != lastAppliedVolume) {
    lastAppliedVolume = mappedVol;
    volumeLevel = mappedVol;
    audio.setVolume(volumeLevel);
  }
}