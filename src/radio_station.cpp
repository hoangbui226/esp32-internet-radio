

Audio audio;
STATION_COUNT = sizeof(stations)/sizeof(stations[0]);
stationIndex = 0;

void startStation(int idx) {
  if (idx < 0) idx = STATION_COUNT - 1;
  if (idx >= STATION_COUNT) idx = 0;
  stationIndex = idx;

  metaTitle = "";
  audio.stopSong();
  delay(100);

  audio.connecttohost(stations[stationIndex].url);
  drawUI("Connecting...");
}