#pragma once

#include "HardwareConsts.hpp"

namespace hw::control::motor
{

template <typename self>
class Motor
{
public:
    
    ~Motor();
    template<typename ...Args>

    void startRotation(Args&& args...)
    {
        // TODO: 
    }
    
    void pinMode(uint8_t pin, lib::MODE mode);

private:
    Motor(/* args */);

    inline self& getContext()
    {
        return static_cast<self&>(*this);
    }

    friend class self;
};
}