#include "app_config.h"
#include "app_state.h"
#include "radio_station.h"
#include "media_player.h"

void audio_info(const char *info) {
  (void)info;
  // Serial.println(info);
}

void audio_showstreamtitle(const char *info) {
  metaTitle = String(info);
}

void audio_eof_mp3(const char *info) {
  (void)info;
}

void media_player_init() {
  audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
}

void media_player_loop() {
  audio.loop();
}

void media_player_start_station(int idx) {
  stationIndex = station_wrap_index(idx);

  metaTitle = "";
  audio.stopSong();
  delay(100);

  const Station& st = station_get(stationIndex);
  audio.connecttohost(st.url);
}
