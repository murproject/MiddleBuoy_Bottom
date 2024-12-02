#pragma once

namespace Pinout {
    namespace Uart {
        HardwareSerial *serialBuoy = &Serial1;
        Serial_ *serialLog = &SerialUSB;

        const unsigned long int serialBuoySpeed = 115200;
        const unsigned long int serialLogSpeed = 115200;
    }

    namespace PWM {
        constexpr int motor = 9;
        constexpr bool invertMotor = true;
    }

    namespace Leds {
        constexpr int bottom = 7;
    }
}
