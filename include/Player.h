#include "Board.h"

class Player {
    char m_symbol;
    string m_name;
public:
    Player(string, char);
    char getSymbol();
    string getName();
    void setSymbol(char);
    void press(int, int, Board&);

    // Player* operator=(const Player&);
    // friend Player* operator=(Player*, const Player*);
};