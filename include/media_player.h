#pragma once
#include <Arduino.h>

void media_player_init();
void media_player_loop();

void media_player_start_station(int idx); //wraps index internally
