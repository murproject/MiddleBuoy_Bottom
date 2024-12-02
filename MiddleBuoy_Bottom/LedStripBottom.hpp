#pragma once

#include "Pinout.hpp"
#include <Adafruit_NeoPixel.h>

namespace LedStrip::Bottom {
    const unsigned int ledsCount = 2;
    const uint8_t colorPowerLevel = 25;
    uint32_t currentColor = 0;

    Adafruit_NeoPixel ledstripBottom(ledsCount, Pinout::Leds::bottom, NEO_GRB + NEO_KHZ800);

    void welcomeIndication() {
        currentColor = Adafruit_NeoPixel::Color(0, 0, colorPowerLevel);
        ledstripBottom.fill(currentColor);
        ledstripBottom.show();
    }

    void begin() {
        ledstripBottom.begin();
        ledstripBottom.clear();
        ledstripBottom.show();
        welcomeIndication();
    }

    void setColor(uint32_t color) {
        currentColor = color;
    }

    void setColor(uint8_t r, uint8_t g, uint8_t b) {
        setColor(Adafruit_NeoPixel::Color(r, g, b));
    }

    void update() {
        ledstripBottom.setPixelColor(0, currentColor);
        ledstripBottom.setPixelColor(1, currentColor);
        ledstripBottom.show();
    }
}
