#pragma once

#include "HardwareConsts.hpp"

#include <utility>
#include <fstream>
#include <iostream>
#include <stddef.h>

namespace hw::control::motor
{

using namespace hw::lib;

enum class DIRECTION
{
    LEFT,
    RIGHT,
    UP,
    DOWN
};

enum class ROTATION
{
    ANTICLOCKWISE = static_cast<int>(DIRECTION::LEFT),
    CLOCKWISE = static_cast<int>(DIRECTION::RIGHT)
};

template <typename self>
class Motor
{
public:
    ~Motor() = default;

    template<typename ...Args>
    void startRotation(Args ...args)
    {
        getContext().startRotation(std::forward<Args>(args)...);
    }

    template<typename ...Args>
    void setSpeed(Args ...args)
    {
        getContext().setSpeed(std::forward<Args>(args)...);
    }

    inline void stop()
    {
        getContext().stop();
    }
    
    inline void pinMode(uint8_t pin, lib::MODE mode)
    {
        FILE* gpioToExport = fopen(GPIO_EXPORT_PATH, "w");
        if(gpioToExport == nullptr)
        {
            std::cerr << "Failed to open export file" << std::endl;
        }
        
        fprintf(gpioToExport, "%d\n", static_cast<uint8_t>(pin));

        fclose(gpioToExport);

        char modePath[50];
        sprintf(modePath, GPIO_MODE, pin);

        FILE* gpioMode = fopen(modePath, "w");

        if(gpioMode == nullptr)
        {
            std::cerr << "Failed to open export file" << std::endl;
        }

        fprintf(gpioMode, "%s\n", lib::DIRECTION[static_cast<uint8_t>(mode)]);

        fclose(gpioMode);
    }

protected:
    inline void write(uint8_t pin, lib::STATE state)
    {
        char gpio[50];

        snprintf(gpio, sizeof(gpio), GPIO_PATH, pin);

        FILE* gpioValue = fopen(gpio, "w");

        if(gpioValue == nullptr)
        {
            std::cerr << "Failed to open value file" << std::endl;
        }

        fprintf(gpioValue, "%d\n", static_cast<uint8_t>(state));
        fclose(gpioValue);
    }
    
    template<typename T>
    T read(uint8_t pin);

private:
    friend self;
    Motor() {}

    inline self& getContext()
    {
        return static_cast<self&>(*this);
    }

    bool digital(uint8_t pin) const;
    double analog(uint8_t pin) const;
};
}