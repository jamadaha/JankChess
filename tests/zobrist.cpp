#include "third_party/doctest.h"
#include <JankChess/types.hpp>
#include <JankChess/zobrist.hpp>
#include <unordered_set>

using namespace Chess;

TEST_CASE("ZOBRIST_ALL_UNIQUE") {
    std::unordered_set<Chess::Hash> hashes;
    for (int i = 0; i < HASH_COUNT; i++)
        hashes.emplace(HASHES[i]);
    CHECK_EQ(hashes.size(), HASH_COUNT);
}
