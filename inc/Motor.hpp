#pragma once

#include "HardwareConsts.hpp"

#include <utility>
namespace hw::control::motor
{
constexpr char GPIO_PATH[] = "/sys/class/gpio/gpio%d/value";
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

//protected:
    void write(uint8_t pin, lib::STATE state);
    
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