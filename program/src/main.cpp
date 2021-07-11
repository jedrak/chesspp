#include <iostream>
#include "Game.h"
#include "Unit.h"
#include "Board.h"

using namespace std;

void print(const unitPtr &unit) {
    cout << unit->getColour() << unit->getType();
}

bool cliObserver(boardPtr board) {
    cout << endl << "   a  b  c  d  e  f  g  h" << endl;
    cout << " -------------------------" << endl;
    for (int y = 7; y >= 0; y--) {
        cout << y + 1;
        for (int x = 0; x < 8; x++) {
            cout << "|";
            if (board->getField(x,y)->occupied())
                print(board->getField(x,y)->getUnit());
            else
                cout << "  ";
        }
        cout << "|" << y + 1 << endl << " -------------------------" << endl;
    }
    cout << "   a  b  c  d  e  f  g  h" << endl << endl;

    return false;
}

class CLIObserver: public Observer
{
public:
    bool notify(boardPtr board) {
        return cliObserver(board);
    }
};

int main() {

    gamePtr game = make_shared<Game>(make_shared<CLIObserver>());
    game->initialize();
    game->simulate();

    return 0;
}