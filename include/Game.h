#include "Player.h"

class Game {
    Player p1;
    Player p2;
    Player* currentPlayer;
    Board board;
public:
    Game(Player&, Player&, Board&);
    ~Game();

    Player* getCurrentPlayer() const;
    void setCurrentPlayer(Player&);
    bool checkWin(char, int, int, Board&);
    void switchPlayer();
};