cmake_minimum_required(VERSION 3.14.0)

project(
    JankChess
    VERSION 1.0.2
    LANGUAGES CXX
)

add_compile_options(
    # Build for specific system instead of distributable
    -march=native
    # Allow inlining inbetween translation units
    -flto -fwhole-program -fuse-linker-plugin
    # Honestly no clue (However, it makes program go fast.)
    -ftracer
)

add_library(
    JankChess
    include/JankChess/bb.hpp
    include/JankChess/board.hpp
    include/JankChess/types.hpp
    include/JankChess/masks.hpp
    include/JankChess/move.hpp
    include/JankChess/move_gen.hpp
    include/JankChess/zobrist.hpp
    src/board.cpp
    src/masks.cpp
    src/move.cpp
    src/move_gen.cpp
    src/zobrist.cpp
)

set_target_properties(
    JankChess
    PROPERTIES
    LINKER_LANGUAGE
    CXX
)

target_include_directories(
    JankChess
    PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>"
)

target_compile_features(
    JankChess
    PUBLIC
    cxx_std_20
)

include(tests/CMakeLists.txt)
include(bin/CMakeLists.txt)
