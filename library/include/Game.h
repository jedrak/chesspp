#ifndef GAME_GAME_H
#define GAME_GAME_H

#include "typedefs.h"
#include "Board.h"
#include "Player.h"

class Game {
private:
    playerPtr player1;
    playerPtr player2;
    playerPtr activePlayer;
    boardPtr board;

public:
    Game();

    virtual ~Game();

    void initialize();

    playerPtr getNextPlayer();

    const boardPtr &getBoard() const;

    void simulate();
};


#endif //GAME_GAME_H
