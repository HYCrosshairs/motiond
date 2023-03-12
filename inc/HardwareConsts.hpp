#pragma once

#include <stdint.h>

namespace hw::lib
{
enum STATE : uint8_t
{
    LOW,
    HIGH
};

enum class MODE : uint8_t
{
    IN,
    OUT
};

constexpr const char* const DIRECTION[] = {
                            "in",
                            "out"
                          };
    
} // namespace hw::lib
