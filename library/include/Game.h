#ifndef GAME_GAME_H
#define GAME_GAME_H

#include "typedefs.h"
#include "Board.h"
#include "Player.h"

class Observer
{
public:
    virtual bool notify(boardPtr board) = 0;
};

typedef std::shared_ptr<Observer> observerPtr;

class Game {
private:
    playerPtr player1;
    playerPtr player2;
    playerPtr activePlayer;
    boardPtr board;
    observerPtr observer;

public:
    Game(const observerPtr &observer);

    const playerPtr &getActivePlayer() const;

    const observerPtr &getObserver() const;

    virtual ~Game();

    void initialize();

    playerPtr getNextPlayer();

    const boardPtr &getBoard() const;

    void simulate();

    void revertMove(std::tuple<unitPtr, fieldPtr, fieldPtr, unitPtr> lastMove);

};


#endif //GAME_GAME_H
