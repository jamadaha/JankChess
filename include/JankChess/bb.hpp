#pragma once

#include <JankChess/types.hpp>

namespace Chess {
// Returns the number of trailing 0-bits in x, starting from the least significant bit
Square lsb(BB x);

// Returns the number of trailing 0-bits in x, starting from the least significant bit, and
Square lsb_pop(BB &x);

// Returns the number of leading 0-bits in x, starting from the most significant bit
Square msb(BB x);

// Returns the number of 1-bits in x
int popcount(BB x);

BB shift_up(BB x, Color color);
} // namespace Chess
