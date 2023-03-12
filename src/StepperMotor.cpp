#include "StepperMotor.hpp"

#include <fstream>
#include <unistd.h>

using namespace hw::control::motor;

StepperMotor::StepperMotor(uint8_t input1, uint8_t input2, uint8_t input3, uint8_t input4) : in1(input1), in2(input2), in3(input3), in4(input4)
{
    std::cout << "StepperMotor constructor\n";
    pinMode(input1, lib::MODE::OUT);
    pinMode(input2, lib::MODE::OUT);
    pinMode(input3, lib::MODE::OUT);
    pinMode(input3, lib::MODE::OUT);
}

StepperMotor::~StepperMotor()
{
    
}

void StepperMotor::startRotation()
{
    std::cout << "StepperMotor startRotation\n";
    
    write(in1, lib::STATE::HIGH);
    write(in2, lib::STATE::HIGH);
    write(in3, lib::STATE::HIGH);
    write(in4, lib::STATE::HIGH);

    usleep(1000000);
    
    write(in1, lib::STATE::LOW);
    write(in2, lib::STATE::LOW);
    write(in3, lib::STATE::LOW);
    write(in4, lib::STATE::LOW);
    usleep(1000000);
}

void StepperMotor::rotateByStep(uint8_t step)
{
    (void)step;
    // TODO : 
}