#include "..\include\Player.h"

Player::Player(string name = "", char symbol = '|') {
    m_name = name;
    m_symbol = symbol;
}

char Player::getSymbol() {
    return m_symbol;
}

string Player::getName() {return m_name;}

void Player::setSymbol(char symbol) {
    m_symbol = symbol;
}

void Player::press(int x, int y, Board& board) {
    board[y][x] = m_symbol;
}

// Player* Player::operator=(const Player & other) {
//     m_symbol = other.m_symbol;
//     m_name = other.m_name;
//     return this;
// }
//
// Player* operator=(Player * asigned, const Player* asign) {
//     asigned = asign;
//     return asigned;
// }
