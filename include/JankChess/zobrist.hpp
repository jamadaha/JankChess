#pragma Once

#include <JankChess/types.hpp>

namespace Chess {
Hash FlipTurn(Hash hash);
Hash FlipCastle(Hash hash, Color color, Castling castling);
Hash FlipEnpassant(Hash hash, Square sq);
Hash FlipSquare(Hash hash, Color color, Piece piece_type, Square square);
} // namespace Chess
