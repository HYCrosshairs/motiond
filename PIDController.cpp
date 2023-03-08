#include "PIDController.hpp"

using namespace service::system::control;

PIDController::PIDController(double kp, double ki, double kd, double setPoint) : mKp(kp), mKi(ki), mKd(kd), mSetPoint(setPoint)
{
}

PIDController::~PIDController()
{
}
