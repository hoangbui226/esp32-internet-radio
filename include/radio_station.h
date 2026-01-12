#pragma once
#include <Arduino.h>

struct Station {
  const char* name;
  const char* url;
};

int stations_count();
const Station& station_get(int idx);
int station_wrap_index(int idx);
