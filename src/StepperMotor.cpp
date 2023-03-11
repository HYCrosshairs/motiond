#include "StepperMotor.hpp"

#include <fstream>

using namespace hw::control::motor;

StepperMotor::StepperMotor(uint8_t input1, uint8_t input2, uint8_t input3, uint8_t input4) : in1(input1), in2(input2), in3(input3), in4(input4)
{
    std::ofstream exportGPIO("/sys/class/gpio/export");

    exportGPIO << input1;
    exportGPIO.close();

    char direction_path[50];
    sprintf(direction_path, "/sys/class/gpio/gpio%d/direction", input1);
    std::ofstream direction_file(direction_path);
    direction_file << "out";
    direction_file.close();
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