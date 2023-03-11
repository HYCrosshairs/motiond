#pragma once

#include "Motor.hpp"
#include "HardwareConsts.hpp"

#include <array>
namespace hw::control::motor
{
constexpr uint8_t MAX_STEPS = 8;
constexpr uint8_t MAX_COILS = 4;

const uint8_t HIGH = 1;
const uint8_t LOW  = 0;

class StepperMotor : public Motor<StepperMotor>
{
public:
    StepperMotor(uint8_t input1, uint8_t input2, uint8_t input3, uint8_t input4);
    ~StepperMotor();

    void startRotation(); // TODO

private:
    uint8_t in1;
    uint8_t in2;
    uint8_t in3;
    uint8_t in4;

    const std::array<std::array<uint8_t, MAX_COILS>, MAX_STEPS> clockwiseRotation = {
        {
            {HIGH, LOW,  LOW,  LOW },
            {HIGH, HIGH, LOW,  LOW },
            {LOW,  HIGH, LOW,  LOW },
            {LOW,  HIGH, HIGH, LOW },
            {LOW,  LOW,  HIGH, LOW },
            {LOW,  LOW,  HIGH, HIGH},
            {LOW,  LOW,  LOW,  HIGH},
            {HIGH, LOW,  LOW,  HIGH}
        }
    };

    void rotateByStep(uint8_t step);
};    
} // namespace hw::control::motor
