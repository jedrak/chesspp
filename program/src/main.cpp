#include "Game.h"
#include "Board.h"
#include <iostream>

using namespace std;

int main() {

    gamePtr game = make_shared<Game>();
    game->initialize();
    game->simulate();

    return 0;
}