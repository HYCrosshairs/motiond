#pragma once

#include "Motor.hpp"
#include "HardwareConsts.hpp"

#include <array>
#include <fstream>
namespace hw::control::motor
{
constexpr uint8_t MAX_STEPS = 8;
constexpr uint8_t MAX_COILS = 4;

using namespace hw::lib;

class StepperMotor : public Motor<StepperMotor>
{
public:
    StepperMotor(uint8_t input1, uint8_t input2, uint8_t input3, uint8_t input4);
    ~StepperMotor();

    void startRotation(uint16_t numOfSteps, uint8_t speed); // TODO

private:
    uint8_t in1;
    uint8_t in2;
    uint8_t in3;
    uint8_t in4;

    uint32_t rotationSpeed;

    const std::array<std::array<uint8_t, MAX_COILS>, MAX_STEPS> clockwiseRotation = {
        {
            {STATE::HIGH, STATE::LOW,  STATE::LOW,  STATE::LOW },
            {STATE::HIGH, STATE::HIGH, STATE::LOW,  STATE::LOW },
            {STATE::LOW,  STATE::HIGH, STATE::LOW,  STATE::LOW },
            {STATE::LOW,  STATE::HIGH, STATE::HIGH, STATE::LOW },
            {STATE::LOW,  STATE::LOW,  STATE::HIGH, STATE::LOW },
            {STATE::LOW,  STATE::LOW,  STATE::HIGH, STATE::HIGH},
            {STATE::LOW,  STATE::LOW,  STATE::LOW,  STATE::HIGH},
            {STATE::HIGH, STATE::LOW,  STATE::LOW,  STATE::HIGH}
        }
    };

    void rotateByStep(uint16_t numOfSteps);

    void setSpeed(uint8_t speed);
};    
} // namespace hw::control::motor
