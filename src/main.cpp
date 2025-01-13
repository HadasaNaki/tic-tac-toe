#include "game.hpp"
#include <iostream>
#include <limits>

void displayBoard(const Board& board) {
    int size = board.getSize();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << board.getCell(i, j);
            if (j < size - 1) std::cout << "|";
        }
        std::cout << "\n";
        if (i < size - 1) {
            for (int j = 0; j < size * 2 - 1; j++) {
                std::cout << "-";
            }
            std::cout << "\n";
        }
    }
    std::cout << "\n";
}

int main() {
    try {
        int size;
        std::cout << "Enter board size (3-10): ";
        std::cin >> size;

        Game game(size);

        while (!game.isGameOver()) {
            displayBoard(game.getBoard());
            std::cout << "Player " << (game.getCurrentPlayerTurn() ? "1 (X)" : "2 (O)") << "'s turn\n";

            int row, col;
            std::cout << "Enter row and column (0-" << size-1 << "): ";
            std::cin >> row >> col;

            if (!std::cin.good()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter numbers.\n";
                continue;
            }

            try {
                if (!game.makeMove(row, col)) {
                    std::cout << "Invalid move. Try again.\n";
                }
            } catch (const std::out_of_range& e) {
                std::cout << "Position out of range. Try again.\n";
            }
        }

        displayBoard(game.getBoard());
        std::string winner = game.getWinner();
        if (!winner.empty()) {
            std::cout << "Winner: " << winner << "!\n";
        } else {
            std::cout << "It's a draw!\n";
        }

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
