#pragma once

#include <JankChess/board.hpp>
#include <JankChess/move.hpp>

namespace Chess {
class Board {
public:
    // Used when restoring state after a move
    struct UndoInformation {
        Square ep;
        std::array<Castling, COLOR_COUNT> castling;
        Piece captured;
    };
    // CONSTRUCTOR

    // Creates a board equvilant to the given FEN string
    Board(std::string FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1") noexcept;
    // Creates a board from a FEN string, then applies a sequence of moves
    Board(const std::string &FEN, const std::string &moves) noexcept;

    // ACCESS

    // Returns the number of moves applied in total
    size_t MoveCount() const noexcept;
    // Returns the number of moves currently applied
    size_t Ply() const noexcept;
    // Returns the color whose turn it is
    Color Turn() const noexcept;
    // Returns the square upon which EP capture is legal
    // In case that no such square exists, SQUARE_NONE is returned
    Square EP() const noexcept;
    // Returns the castling rights of the color
    Castling GetCastling(Color color) const noexcept;
    // Returns the current position's hash
    Hash GetHash() const noexcept;
    // Returns all pieces
    BB Pieces() const noexcept;
    // Returns pieces of type
    BB Pieces(Piece piece) const noexcept;
    // Returns pieces of color
    BB Pieces(Color color) const noexcept;
    // Returns pieces of type and color
    BB Pieces(Color color, Piece piece) const noexcept;
    // Returns the type of piece on given square
    Piece SquarePiece(Square square) const noexcept;
    // Returns the color of piece on given square
    Color SquareColor(Square square) const noexcept;
    // Returns whether the king of a color is under attack
    bool IsKingSafe(Color color) const noexcept;
    // Returns an attack bitboard
    BB GenerateAttacks(Color color) const noexcept;

    // MODIFIERS

    // Resets board to an empty state
    void ClearBoard();
    // Modifies board to a state where a piece of given color is on square
    void PlacePiece(Color color, Piece piece, Square square) noexcept;
    // Modifies board to a state where no piece of color is on square
    void RemovePiece(Color color, Piece piece, Square square) noexcept;
    // Modifies board to a state where the move is applied
    UndoInformation ApplyMove(Move move) noexcept;
    // Modifies board to a state where the move is undone
    void UndoMove(Move move, UndoInformation info) noexcept;

private:
    BB pieces[PIECE_COUNT];
    BB colors[COLOR_COUNT];
    Color turn;
    Square ep;
    std::array<Castling, COLOR_COUNT> castling;
    Hash hash;
    size_t move_count;
    size_t ply;

    void FlipPiece(Color color, Piece piece, Square square) noexcept;
};
} // namespace Chess