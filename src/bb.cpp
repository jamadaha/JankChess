#include <JankChess/bb.hpp>

namespace Chess {
Square lsb(BB x) {
    assert(x != 0);
    return static_cast<Square>(__builtin_ctzll(x));
}

Square lsb_pop(BB &x) {
    assert(x != 0);
    const int t = lsb(x);
    x &= x - 1;
    return static_cast<Square>(t);
}

Square msb(BB x) {
    assert(x != 0);
    static_assert(sizeof(BB) == 8);
    return static_cast<Square>(63 ^ __builtin_clzll(x));
}

int popcount(BB x) { return __builtin_popcountll(x); }

BB shift_up(BB x, Color color) {
    if (color == WHITE)
        return x << 8;
    else
        return x >> 8;
}
} // namespace Chess
