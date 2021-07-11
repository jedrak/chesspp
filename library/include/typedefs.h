#ifndef GAME_TYPEDEFS_H
#define GAME_TYPEDEFS_H

#include <memory>

class Player;
typedef std::shared_ptr<Player> playerPtr;

class Field;
typedef std::shared_ptr<Field> fieldPtr;

class Unit;
typedef std::shared_ptr<Unit> unitPtr;

class Board;
typedef std::shared_ptr<Board> boardPtr;

class Game;
typedef std::shared_ptr<Game> gamePtr;

#endif //GAME_TYPEDEFS_H
