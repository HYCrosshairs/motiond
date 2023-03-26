#pragma once

#include "Motor.hpp"

namespace hw::control::motor
{

class ServoMotor : public Motor<ServoMotor>
{
public:
    ServoMotor(uint8_t channel, uint16_t minPulseWidth = 500, uint16_t maxPulseWidth = 2500);
    ~ServoMotor();

    void startRotation(uint16_t angle, ROTATION direction, uint8_t speed);

    void stop();

private:
    uint8_t channel;
    uint16_t minPulseWidth;
    uint16_t maxPulseWidth;
    uint8_t pwmFd;
    uint8_t speed;
    uint16_t currentAngle;
    ROTATION direction;

    void setAngle(uint16_t angle, bool clockWise = true);

};

} // namespace hw::control::motor