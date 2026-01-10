#pragma once

extern const int STATION_COUNT;

struct Station {
  const char* name;
  const char* url;
};

Station stations[] = {
  {"VOV1", "https://stream.vovmedia.vn/vov1"},
  {"VOV Giao Thong", "https://play.vovgiaothong.vn/live/gthn/playlist.m3u8"},
  {"QNTV", "https://live.baoquangninh.vn/qtvlive/qnr2.m3u8"}
};