#include "StepperMotor.hpp"

#include <fstream>
#include <unistd.h>

using namespace hw::control::motor;

StepperMotor::StepperMotor(uint8_t input1, uint8_t input2, uint8_t input3, uint8_t input4) : in1(input1), in2(input2), in3(input3), in4(input4)
{
    pinMode(input1, lib::MODE::OUT);
    pinMode(input2, lib::MODE::OUT);
    pinMode(input3, lib::MODE::OUT);
    pinMode(input4, lib::MODE::OUT);
}

StepperMotor::~StepperMotor()
{
    
}

void StepperMotor::startRotation(uint16_t numOfSteps, uint8_t speed)
{
    setSpeed(speed);
    
    rotateByStep(numOfSteps);
}

void StepperMotor::rotateByStep(uint16_t numOfSteps)
{
    uint16_t stepCount = 0;

    while (stepCount < numOfSteps)
    {
        for (uint8_t step = 0; step < MAX_STEPS; step++)
        {
            write(in1, static_cast<STATE>(clockwiseRotation[step][0]));
            write(in2, static_cast<STATE>(clockwiseRotation[step][1]));
            write(in3, static_cast<STATE>(clockwiseRotation[step][2]));
            write(in4, static_cast<STATE>(clockwiseRotation[step][3]));
            usleep(rotationSpeed);
        }
        stepCount++;
    }

}

void StepperMotor::setSpeed(uint8_t speed)
{
    rotationSpeed = speed * 1000000;
}