#pragma Once

#include <JankChess/types.hpp>

namespace Chess {
// Consists of turn key, castling rights, EP squares, Piece squares
constexpr size_t HASH_COUNT = 1 + 4 * 2 + SQUARE_COUNT + COLOR_COUNT * PIECE_COUNT * SQUARE_COUNT;
extern const std::array<Hash, HASH_COUNT> HASHES;

Hash FlipTurn(Hash hash);
Hash FlipCastle(Hash hash, Color color, Castling castling);
Hash FlipEnpassant(Hash hash, Square sq);
Hash FlipSquare(Hash hash, Color color, Piece piece_type, Square square);
} // namespace Chess
