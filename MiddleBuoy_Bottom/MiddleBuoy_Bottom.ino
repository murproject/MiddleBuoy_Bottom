#include "Pinout.hpp"
#include "MotorDriver.hpp"
#include "LedStripBottom.hpp"
#include "Depth.hpp"
#include "UART.hpp"
#include "Protocol.hpp"

void setup() {
    Motor::Driver::begin();
    UART::begin();
    LedStrip::Bottom::begin();
    Depth::begin();
}

void receiveControl() {
    UART::receiveWhileAvailable(&Protocol::packetControl);
}

void sendTelemetry() {
    auto &telemetry = Protocol::packetTelemetry;
    Depth::updateTelemetry();
    telemetry.uptime = millis() / 1000;
    UART::transmitPacket(&telemetry);
}

void updateMotor() {
    auto &control = Protocol::packetControl;
    Motor::Driver::writePower(control.motorPower);
}

void updateLeds() {
    auto &control = Protocol::packetControl;

    LedStrip::Bottom::setColor(
        control.ledR,
        control.ledG,
        control.ledB
    );

    LedStrip::Bottom::update();
}

void killswitch() {
    Motor::Driver::stop();
    LedStrip::Bottom::setColor(10, 0, 10);
    LedStrip::Bottom::update();
}

void loop() {
    receiveControl();

    if (UART::isPacketTimeout()) {
        killswitch();
    } else {
        updateMotor();
        updateLeds();
    }

    sendTelemetry();

    delay(10);
}
