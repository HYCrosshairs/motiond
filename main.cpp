#include "StepperMotor.hpp"
//#include "HardwareConsts.hpp"

using namespace hw::control::motor;

int main()
{
    StepperMotor stepper(21, 15, 16, 17);

    while (true)
    {
        stepper.startRotation();
    }
    
    return 0;
}
