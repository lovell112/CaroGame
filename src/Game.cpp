#include "..\include\Game.h"

// #include <bits/ranges_algo.h>

Game::Game(Player& _p1, Player& _p2, Board& _board): p1(_p1), p2(_p2), board(_board) {}

Game::~Game() {}

void Game::setCurrentPlayer(Player & people) {
    currentPlayer = &people;
}

Player* Game::getCurrentPlayer() const {
    return currentPlayer;
}

bool Game::checkWin(char symbol, int x, int y, Board& _board) {
    if (_board[y][x]==' ')
        return false;

    const int winCondition = 5;

    auto countDirection = [&](int dimX, int dimY) {
        int count = 1;

        for (int step = 1; step <= winCondition; step++) {
            int newX = x + dimX*step;
            int newY = y + dimY*step;
            if (newX<=0||newX>=_board.getCol()-1||newY<=0||newY>=_board.getRow()-1||_board[newY][newX]!=symbol)
                break;
            count++;
        }

        for (int step = 1; step <= winCondition; step++) {
            int newX = x - dimX*step;
            int newY = y - dimY*step;
            if (newX<=0||newX>=_board.getCol()-1||newY<=0||newY>=_board.getRow()-1||_board[newY][newX]!=symbol)
                break;
            count++;
        }

        return count;
    };

    if (countDirection(1, 0)>=winCondition) return true;
    if (countDirection(0, 1)>=winCondition) return true;
    if (countDirection(1, 1)>=winCondition) return true;
    if (countDirection(1, -1)>=winCondition) return true;

    return false;
}

void Game::switchPlayer() {
    if (currentPlayer->getSymbol()==p1.getSymbol())
        currentPlayer = &p2;
    else
        currentPlayer = &p1;
}