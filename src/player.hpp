#pragma once
#include <string>

class Player {
private:
    std::string name;
    char symbol;

public:
    Player(const std::string& playerName, char playerSymbol)
        : name(playerName), symbol(playerSymbol) {
        if (symbol != 'X' && symbol != 'O') {
            throw std::invalid_argument("Symbol must be 'X' or 'O'");
        }
    }

    std::string getName() const { return name; }
    char getSymbol() const { return symbol; }
};
