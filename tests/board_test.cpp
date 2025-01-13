#include <gtest/gtest.h>
#include "../board.hpp"

TEST(BoardTest, InitialBoardIsEmpty) {
    Board board(3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            EXPECT_EQ(board.getCell(i, j), ' ');
        }
    }
}

TEST(BoardTest, MakeMoveSuccessful) {
    Board board(3);
    EXPECT_TRUE(board.makeMove(0, 0, 'X'));
    EXPECT_EQ(board.getCell(0, 0), 'X');
}

TEST(BoardTest, MakeMoveFails) {
    Board board(3);
    board.makeMove(0, 0, 'X');
    EXPECT_FALSE(board.makeMove(0, 0, 'O'));
}

TEST(BoardTest, CheckWinRow) {
    Board board(3);
    board.makeMove(0, 0, 'X');
    board.makeMove(0, 1, 'X');
    board.makeMove(0, 2, 'X');
    EXPECT_TRUE(board.checkWin('X'));
}
