#include "ServoMotor.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <linux/pwm.h> 

using namespace hw::control::motor;

ServoMotor::ServoMotor(uint8_t channel, uint16_t minPulseWidth, uint16_t maxPulseWidth) : channel(channel), minPulseWidth(minPulseWidth), maxPulseWidth(maxPulseWidth)
{
    char file[20];
    snprintf(file, sizeof(file), PWM_CHANNEL, 0);

    pwmFd = open(file, O_WRONLY);

    if (pwmFd < 0)
    {
        perror("Failed to open PWM device");
        exit(1);
    }

    uint32_t periodNs = 1'000'000'000 / 50;  // 50 Hz

    ioctl(pwmFd, PWM_IOCTL_SET_PERIOD, &periodNs);
    setAngle(90);
}

ServoMotor::~ServoMotor()
{
    setAngle(90);
    stop();
}

void ServoMotor::startRotation(uint16_t angle, ROTATION direction, uint8_t speed)
{
    // TODO
}

void ServoMotor::stop()
{
    close(pwmFd);
}

void ServoMotor::setAngle(uint16_t angle, bool clockWise)
{
    if (angle < 0)
    {
        angle = 0;
    }
    else if(angle > 180)
    {
        angle = 180;
    }

    uint16_t pulseWidthUs = minPulseWidth + angle * (maxPulseWidth - minPulseWidth) / 180;
    uint16_t dutyCycleNs = pulseWidthUs * 1'000;
    int16_t pwm_value = duty_cycle_ns * 4'096 / 1'000'000'000;
    
    struct pwmDutyCycle cycle = { 0, pwm_value };
    
    ioctl(pwmFd, PWM_IOCTL_SET_DUTY_CYCLE, &cycle);
    struct pwmDutyCycle cycles[1] = { cycle };
    ioctl(pwmFd, PWM_IOCTL_SET_DUTY_CYCLE, &cycles);
    
    if (clockWise)
    {
        direction = ROTATION::CLOCKWISE;
    }
    else 
    {
        direction = ROTATION::ANTICLOCKWISE;
    }

}