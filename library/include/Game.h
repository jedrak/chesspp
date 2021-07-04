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
    std::tuple<unitPtr, fieldPtr, fieldPtr, unitPtr> lastMove;

public:
    Game();

    virtual ~Game();

    void initialize();

    playerPtr getOtherPlayer();

    const boardPtr &getBoard() const;

    void simulate();
    void revertMove();
};


#endif //GAME_GAME_H
