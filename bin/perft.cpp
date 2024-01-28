#include <JankChess/board.hpp>
#include <JankChess/move_gen.hpp>
#include <cstdio>

using namespace Chess;

size_t Perft(Board &board, int depth) {
    if (depth == 0) return 1;
    MoveList moves;
    GenerateMovesAll(moves, board, board.Turn());

    size_t nodes = 0;

    for (const auto &move : moves) {
        const auto info = board.ApplyMove(move);
        if (board.IsKingSafe(!board.Turn())) nodes += Perft(board, depth - 1);
        board.UndoMove(move, info);
    }

    return nodes;
}

void PerftDivide(Board &board, int depth) {
    if (depth == 0) {
        printf("0\n");
        return;
    }
    size_t total = 0;

    const MoveList moves = GenerateMovesAll(board, board.Turn());

    for (const auto move : moves) {
        const auto info = board.ApplyMove(move);

        if (board.IsKingSafe(!board.Turn())) {
            const size_t nodes = Perft(board, depth - 1);
            printf("%s %zu\n", move.Export().c_str(), nodes);
            total += nodes;
        }

        board.UndoMove(move, info);
    }

    printf("\n%zu\n", total);
}

int main(int argc, char **argv) {
    const size_t depth    = std::stoi(argv[1]);
    const std::string FEN = std::string(argv[2]);
    Board board;
    if (argc == 3)
        board = Board(FEN);
    else
        board = Board(FEN, argv[3]);

    PerftDivide(board, depth);

    return 0;
}
