#include "StepperMotor.hpp"

using namespace hw::control::motor;

StepperMotor::StepperMotor(uint8_t input1, uint8_t input2, uint8_t input3, uint8_t input4) : in1(input1), in2(input2), in3(input3), in4(input4)
{
    // set pins mode
}

StepperMotor::~StepperMotor()
{
}

void StepperMotor::startRotation()
{
    
}

void StepperMotor::rotateByStep(uint8_t step)
{
    (void)step;
    // TODO : 
}