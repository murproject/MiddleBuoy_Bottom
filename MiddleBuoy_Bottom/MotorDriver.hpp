#pragma once

#include "Pinout.hpp"
#include <Servo.h>

namespace Motor::Driver {
    const int maxMotorPower = 90;
    const unsigned int pulseMin = 1000;
    const unsigned int pulseMax = 2000;

    Servo motorPwm;

    void writePower(int power) {
        power *= Pinout::PWM::invertMotor ? -1 : +1;
        power = constrain(power, -100, +100);
        int motorPowerLimited = map(power, -100, +100, -maxMotorPower, +maxMotorPower);

        uint16_t pulsewidth = map(motorPowerLimited, -100, +100, pulseMin, pulseMax);
        pulsewidth = constrain(pulsewidth, pulseMin, pulseMax);

        motorPwm.writeMicroseconds(pulsewidth);
    }

    void stop() {
        writePower(0);
    }

    void begin() {
        motorPwm.attach(Pinout::PWM::motor);
        stop();
    }
}
