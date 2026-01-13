#include "radio_station.h"

static Station stations[] = {
  {"VOV Giao Thong",                "https://play.vovgiaothong.vn/live/gthn/playlist.m3u8"},
  {"VOH FM Nhip Song 77",           "https://strm.voh.com.vn/radio/channel5/playlist.m3u8"},
  {"RFI Tieng Viet",                "https://rfienvietnamien64k.ice.infomaniak.ch/rfienvietnamien-64.mp3"},
  {"Vietnamese National People",    "https://c13.radioboss.fm:8127/autodj"},
  {"VOH AM Nong Thon",              "https://strm.voh.com.vn/radio/channel2/playlist.m3u8"},
  {"VOH FM Dem Thanh Pho",          "https://strm.voh.com.vn/radio/channel1/playlist.m3u8"},
  {"VOH FM Khong Gioi Han",         "https://strm.voh.com.vn/radio/channel3/playlist.m3u8"},
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
