#pragma once

#include <Wire.h>
#include <MS5837.h>

#include "Protocol.hpp"

namespace Depth {
    MS5837 depthSensor;
    bool started = false;

    void updateTelemetry() {
        auto t = &Protocol::packetTelemetry;

        if (!started) {
            t->depth = 0;
            t->pressure = 0;
            t->altitude = 0;
            t->temperature = 0;

            return;
        }

        depthSensor.read();

        auto toFixed = [](float value) -> int32_t {
            return round(value * 1000);
        };

        t->depth = toFixed(depthSensor.depth());
        t->pressure = toFixed(depthSensor.pressure());
        t->altitude = toFixed(depthSensor.altitude());
        t->temperature = toFixed(depthSensor.temperature());
    }

    void begin() {
        Wire.begin();
        Wire.setTimeout(50);

        started = depthSensor.init();

        if (!started) {
            return;
        }

        depthSensor.setModel(MS5837::MS5837_30BA);
        depthSensor.setFluidDensity(997);
    }
}
