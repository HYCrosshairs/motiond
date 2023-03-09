#include "Motor.hpp"

#include <type_traits>

using namespace hw::control::motor;

template<typename self>
inline void Motor<self>::pinMode(uint8_t pin, lib::MODE mode)
{
    // TODO: configure a specific pin
}

template<typename self>
inline void Motor<self>::write(uint8_t pin, lib::STATE)
{
    // TODO
}

template<typename self>
template<typename T>
inline T Motor<self>::read(uint8_t pin)
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