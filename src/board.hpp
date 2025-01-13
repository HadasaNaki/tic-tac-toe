#pragma once
#include <vector>
#include <stdexcept>

class Board {
private:
    std::vector<std::vector<char>> grid;
    int size;

public:
    Board(int boardSize = 3) : size(boardSize) {
        if (boardSize < 3 || boardSize > 10) {
            throw std::invalid_argument("Board size must be between 3 and 10");
        }
        grid.resize(size, std::vector<char>(size, ' '));
    }

    bool makeMove(int row, int col, char symbol) {
        if (row < 0 || row >= size || col < 0 || col >= size) {
            throw std::out_of_range("Invalid position");
        }
        if (grid[row][col] != ' ') {
            return false;
        }
        grid[row][col] = symbol;
        return true;
    }

    bool checkWin(char symbol) const {
        // Check rows
        for (int i = 0; i < size; i++) {
            bool win = true;
            for (int j = 0; j < size; j++) {
                if (grid[i][j] != symbol) {
                    win = false;
                    break;
                }
            }
            if (win) return true;
        }

        // Check columns
        for (int j = 0; j < size; j++) {
            bool win = true;
            for (int i = 0; i < size; i++) {
                if (grid[i][j] != symbol) {
                    win = false;
                    break;
                }
            }
            if (win) return true;
        }

        // Check diagonals
        bool win = true;
        for (int i = 0; i < size; i++) {
            if (grid[i][i] != symbol) {
                win = false;
                break;
            }
        }
        if (win) return true;

        win = true;
        for (int i = 0; i < size; i++) {
            if (grid[i][size-1-i] != symbol) {
                win = false;
                break;
            }
        }
        return win;
    }

    bool isFull() const {
        for (const auto& row : grid) {
            for (char cell : row) {
                if (cell == ' ') return false;
            }
        }
        return true;
    }

    char getCell(int row, int col) const {
        if (row < 0 || row >= size || col < 0 || col >= size) {
            throw std::out_of_range("Invalid position");
        }
        return grid[row][col];
    }

    int getSize() const {
        return size;
    }
};
