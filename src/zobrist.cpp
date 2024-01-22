#include <JankChess/zobrist.hpp>

namespace Chess {
// Consists of turn key, castling rights, EP squares, Piece squares
constexpr size_t HASH_COUNT = 1 + 4 * 2 + SQUARE_COUNT + COLOR_COUNT * PIECE_COUNT * SQUARE_COUNT;

// Generate hashses in a pseudo-random way
// Cannot use *actual* randomness as its compile time
// This is, however, good enough
constexpr std::array<uint64_t, HASH_COUNT> HASHES = [] {
    auto tempTable = decltype(HASHES){};

    uint64_t lfsr = 0x181818ffff181818;
    uint64_t bit;

    for (int i = 0; i < HASH_COUNT; i++) {
        bit          = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5)) & 1u;
        lfsr         = (lfsr >> 1) | (bit << 63);
        tempTable[i] = lfsr;
    }

    return tempTable;
}();

Hash FlipTurn(Hash hash) { return hash ^ HASHES[0]; }
Hash FlipCastle(Hash hash, Color color, Castling castling) {
    return hash ^ HASHES[1 + color * static_cast<int>(castling)];
}
Hash FlipEnpassant(Hash hash, Square sq) { return hash ^ HASHES[1 + 8 + sq]; }
Hash FlipSquare(Hash hash, Color color, Piece piece_type, Square square) {
    return hash ^ HASHES[1 + 8 + SQUARE_COUNT + color * static_cast<int>(piece_type) * square];
}
} // namespace Chess
