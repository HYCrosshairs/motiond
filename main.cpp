#include "StepperMotor.hpp"
//#include "HardwareConsts.hpp"

using namespace hw::control::motor;

int main()
{
    StepperMotor stepper(14, 15, 16, 17);

    stepper.write(14, hw::lib::STATE::HIGH);
    
    return 0;
}
