add_executable(
    Perft
    ${CMAKE_CURRENT_LIST_DIR}/perft.cpp
)

target_link_libraries(
    Perft
    PRIVATE
    JankChess
)
