#include <math.h>
#include "app_config.h"
#include "app_state.h"
#include "volume_updater.h"

static int map_pot_to_volume(float pot) {
  int mapped = (int)lroundf((pot / 4095.0f) * (VOL_MAX - VOL_MIN) + VOL_MIN);
  if (mapped < VOL_MIN) mapped = VOL_MIN;
  if (mapped > VOL_MAX) mapped = VOL_MAX;
  return mapped;
}

void volume_init_from_pot() {
  potFiltered = (float)analogRead(POT_PIN);
  lastAppliedVolume = -1;
  volume_update_from_pot();
}

void volume_update_from_pot() {
  if (millis() - lastVolReadMs < POT_READ_MS) return;
  lastVolReadMs = millis();

  const int raw = analogRead(POT_PIN);

  // Low-pass filter
  const float alpha = 0.20f;
  potFiltered = (potFiltered == 0.0f) ? (float)raw : (alpha * (float)raw + (1.0f - alpha) * potFiltered);

  const int mappedVol = map_pot_to_volume(potFiltered);

  if (mappedVol != lastAppliedVolume) {
    lastAppliedVolume = mappedVol;
    volumeLevel = mappedVol;
    audio.setVolume(volumeLevel);
  }
}
