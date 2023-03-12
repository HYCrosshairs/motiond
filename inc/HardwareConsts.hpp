#pragma once

#include <stdint.h>

namespace hw::lib
{
enum class STATE : uint8_t
{
    LOW,
    HIGH
};

enum class MODE : uint8_t
{
    IN,
    OUT
};

constexpr char* DIRECTION[] = {
                            "in",
                            "out"
                          };
    
} // namespace hw::lib
