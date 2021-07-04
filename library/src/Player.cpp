#include "Game.h"
#include "Player.h"
#include "Board.h"
#include "Unit.h"
#include <iostream>



using namespace std;

 bool Player::inCheck() {
     return false;
 }

 std::string Player::getName() const {
     return _name;
 }

 bool Player::isWhite() const {
     return false;
 }

 bool Player::makeMove() {
     string badInput;
     string fromSquare =  "  ";
     string toSquare = "  ";
     int fromX;
     int fromY;
     int toX;
     int toY;
     char X_MIN = 'a';
     char X_MAX = 'h';
     char Y_MIN = '1';
     char Y_MAX = '8';

     cin >> fromSquare >> toSquare;

     cout << _name << " player enter move (e.g. a2 a4): ";

     while(fromSquare.length() != 2 ||
           toSquare.length() != 2 ||
           tolower(fromSquare.at(0)) < X_MIN ||
           tolower(fromSquare.at(0)) > X_MAX ||
           tolower(toSquare.at(0)) < X_MIN ||
           tolower(toSquare.at(0)) > X_MAX ||
           tolower(fromSquare.at(1)) < Y_MIN ||
           tolower(fromSquare.at(1)) > Y_MAX ||
           tolower(toSquare.at(1)) < Y_MIN ||
           tolower(toSquare.at(1)) > Y_MAX ||
           !(getGame()->getBoard()->getField(tolower(fromSquare[0]) - X_MIN,
                                         tolower(fromSquare[1]) - Y_MIN)->occupied())
             )
     {
         cerr << "Invalid move. Try again." << endl;
         cin.clear();
         getline(cin, badInput);
         cout << _name << " player enter move (e.g. a2 a4): ";
         cin >> fromSquare >> toSquare;
     }

     fromX = tolower(fromSquare.at(0)) - X_MIN;
     fromY = tolower(fromSquare.at(1)) - Y_MIN;
     toX = tolower(toSquare.at(0)) - X_MIN;
     toY = tolower(toSquare.at(1)) - Y_MIN;

     return getGame()->getBoard()->getField(fromX, fromY)->getUnit()->move(toX, toY);
 }

 Player::Player(const string &name) : _name(name) {}

 Player::~Player() {

 }

const gamePtr &Player::getGame() const {
    return game;
}
