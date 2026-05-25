#pragma once

#include <Arduino.h>

namespace Throttle {
    struct Config {
        float voltageMin;
        float voltageMax;
    };

    struct Data {
        float volts;
        float pct;
    };

    void defaultValue();
    void loop();

    float getVolts();
    float getPct();
    float getVoltageMin();
    float getVoltageMax();
}