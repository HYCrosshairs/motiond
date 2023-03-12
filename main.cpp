#include "StepperMotor.hpp"
//#include "HardwareConsts.hpp"

using namespace hw::control::motor;

int main()
{
    StepperMotor stepper(21, 22, 4, 5);

    while (true)
    {
        stepper.startRotation(16, 1);
    }
    
    return 0;
}
