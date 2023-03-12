#include "Motor.hpp"
#include <fstream>

#include <type_traits>

using namespace hw::control::motor;

template<typename self>
template<typename T>
T Motor<self>::read(uint8_t pin)
{
    if constexpr(std::is_same_v<T, lib::STATE>)
    {
        bool state = digital();
        return state ? lib::STATE::HIGH : lib::STATE::LOW; 
    }
    else if constexpr(std::is_same_v<T, double>)
    {
        double value = analog(); // TODO: maybe some explicit casting is needed (floating-point value)
        return value;
    }
    else
    {
        static_assert(sizeof(T) == 0, "Unsupported type"); // TODO: Write a specific class error handler
    }       
}

template<typename self>
bool Motor<self>::digital(uint8_t pin) const
{
    // TODO
    return false;
}

template<typename self>
double Motor<self>::analog(uint8_t pin) const
{
    // TODO
    return 0.0;
}