#pragma once
#include <Arduino.h>

void wifi_connect_blocking(uint32_t timeout_ms);
bool wifi_is_connected();
