#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include <string>
#include "typedefs.h"

class Player {
private:
    std::string _name;
    gamePtr game;
public:
    std::string getName() const;

    Player(const std::string &name);

    virtual ~Player() = 0;

    bool makeMove();

    bool inCheck();

    bool isWhite() const;

    const gamePtr &getGame() const;
};

#endif //GAME_PLAYER_H
