#pragma once

#include "HardwareConsts.hpp"

#include <utility>
namespace hw::control::motor
{
template <typename self>
class Motor
{
public:
    ~Motor() = default;

    template<typename ...Args>
    void startRotation(Args&& ...args)
    {
        getContext().startRotation(std::forward<Args>(args)...);
    }
    
    void pinMode(uint8_t pin, lib::MODE mode);

protected:
    void write(uint8_t pin, lib::STATE);
    template<typename T>
    T read(uint8_t pin);

private:
    friend self;
    Motor() {}

    inline self& getContext()
    {
        return static_cast<self&>(*this);
    }

    bool digital() const; // TODO
    double analog() const; // TODO
};
}