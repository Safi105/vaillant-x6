#pragma once
#include <cstdint>

class ResponseDecoder {
 public:
  // vorhandene Funktion: 2-Byte signed -> float (geteilt durch 16)
  static float analogueValue2Bytes(const uint8_t* response) {
    int16_t i = (static_cast<int16_t>(response[0]) << 8) | response[1];
    return i / (16.0f);
  }

  // Kombiniertes Ergebnis für 2-Byte-Analogue + 1-Byte-Status
  struct AnalogueWithStatus {
    float value;
    uint8_t status;
  };

  // Erwartet mindestens 3 Bytes: [0],[1] = 2-Byte Wert, [2] = Status
  static AnalogueWithStatus analogueValueWithStatus(const uint8_t* response) {
    AnalogueWithStatus r;
    int16_t i = (static_cast<int16_t>(response[0]) << 8) | response[1];
    r.value = i / (16.0f);
    r.status = response[2];
    return r;
  }
};
