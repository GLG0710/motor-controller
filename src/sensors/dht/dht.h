#pragma once

#include "config/pins.h"

#include <DHT.h>
#include <Arduino.h>

#define DHTTYPE DHT22

inline constexpr uint32_t DHT_MS = 2000;

namespace Dht {
    struct Data {
        float temp = NAN;
        float humi = NAN;
    };

    void setup();
    void loop(uint32_t now);

    float getTemp();
    float getHumi();
}