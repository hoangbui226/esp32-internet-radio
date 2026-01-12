#include "radio_station.h"

static Station stations[] = {
  {"SomaFM Groove Salad", "http://ice1.somafm.com/groovesalad-128-mp3"},
  {"SomaFM Drone Zone",   "http://ice1.somafm.com/dronezone-128-mp3"},
  {"BBC World Service",   "http://stream.live.vc.bbcmedia.co.uk/bbc_world_service"}
};

int stations_count() {
  return (int)(sizeof(stations) / sizeof(stations[0]));
}

int station_wrap_index(int idx) {
  const int n = stations_count();
  if (n <= 0) return 0;
  while (idx < 0) idx += n;
  while (idx >= n) idx -= n;
  return idx;
}

const Station& station_get(int idx) {
  idx = station_wrap_index(idx);
  return stations[idx];
}
