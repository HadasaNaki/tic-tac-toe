#pragma once
#include "board.hpp"
#include "player.hpp"
#include <memory>

class Game {
private:
    Board board;
    Player player1;
    Player player2;
    bool isPlayer1Turn;

public:
    Game(int size = 3)
        : board(size),
          player1("Player 1", 'X'),
          player2("Player 2", 'O'),
          isPlayer1Turn(true) {}

    bool makeMove(int row, int col) {
        Player& currentPlayer = isPlayer1Turn ? player1 : player2;
        bool success = board.makeMove(row, col, currentPlayer.getSymbol());
        if (success) {
            isPlayer1Turn = !isPlayer1Turn;
        }
        return success;
    }

    bool isGameOver() const {
        return board.checkWin('X') || board.checkWin('O') || board.isFull();
    }

    std::string getWinner() const {
        if (board.checkWin('X')) return player1.getName();
        if (board.checkWin('O')) return player2.getName();
        return "";
    }

    const Board& getBoard() const { return board; }
    bool getCurrentPlayerTurn() const { return isPlayer1Turn; }
};
