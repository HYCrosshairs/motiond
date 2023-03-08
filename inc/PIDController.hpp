#pragma once

namespace service::system::control
{
class PIDController
{
public:
    PIDController(double kp, double ki, double kd, double setPoint);
    ~PIDController();

private:
    double mKp;
    double mKi;
    double mKd;
    double mSetPoint;
    double mPrevError;
    double mIntegral;
    
};
    
} // namespace service::system::control
