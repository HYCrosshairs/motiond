#pragma once

#include "Motor.hpp"

namespace hw::control::motor
{

class ServoMotor : public Motor<ServoMotor>
{
public:
    ServoMotor();
    ~ServoMotor();

    void startRotation();

    void stop();

private:
    int pwmFd;
    uint8_t speed;
    uint8_t currentAngle;
    DIRECTION direction;

    void setAngle();

};

} // namespace hw::control::motor