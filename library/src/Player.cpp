#include "Game.h"
#include "Player.h"
#include "Board.h"
#include "Unit.h"
#include <iostream>
#include <utility>
#include <sstream>
#include <algorithm>


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

 /*bool Player::makeMove() {
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

 Player::Player(string name) : _name(std::move(name)) {}

 Player::~Player() {

 }*/

const gamePtr &Player::getGame() const {
    return game;
}

Player::Player(string name, gamePtr game, char color) : _name(std::move(name)), game(std::move(game)), color(color){
    pieces = std::vector<unitPtr>();
    allPossibleMoves = std::vector<std::tuple<unitPtr, std::vector<fieldPtr>>>();
}

void Player::setup() {
    if(this->color == 'W'){
        for (int i = 0; i < 8; ++i) {
            fieldPtr field = this->game->getBoard()->getField(i, 1);
            unitPtr buff = std::make_shared<Pawn>(color, field);
            pieces.push_back(buff);
            field->setUnit(buff);
        }
        //rooks
        fieldPtr field = this->game->getBoard()->getField(0, 0);
        unitPtr buff = std::make_shared<Rook>(color, field);
        pieces.push_back(buff);
        field->setUnit(buff);

        field = this->game->getBoard()->getField(7, 0);
        buff = std::make_shared<Rook>(color, field);
        pieces.push_back(buff);
        field->setUnit(buff);

        //knights
        field = this->game->getBoard()->getField(1, 0);
        buff = std::make_shared<Knight>(color, field);
        pieces.push_back(buff);
        field->setUnit(buff);

        field = this->game->getBoard()->getField(6, 0);
        buff = std::make_shared<Knight>(color, field);
        pieces.push_back(buff);
        field->setUnit(buff);


        //bishops
        field = this->game->getBoard()->getField(2, 0);
        buff = std::make_shared<Bishop>(color, field);
        pieces.push_back(buff);
        field->setUnit(buff);

        field = this->game->getBoard()->getField(5, 0);
        buff = std::make_shared<Bishop>(color, field);
        pieces.push_back(buff);
        field->setUnit(buff);

        //queen
        field = this->game->getBoard()->getField(3, 0);
        buff = std::make_shared<Queen>(color, field);
        pieces.push_back(buff);
        field->setUnit(buff);

        //king
        field = this->game->getBoard()->getField(4, 0);
        buff = std::make_shared<King>(color, field);
        pieces.push_back(buff);
        field->setUnit(buff);
        king = buff;
    }
    else
    {
        for (int i = 0; i < 8; ++i) {
            fieldPtr field = this->game->getBoard()->getField(i, 6);
            unitPtr buff = std::make_shared<Pawn>(color, field);
            pieces.push_back(buff);
            field->setUnit(buff);
        }
        //rooks
        fieldPtr field = this->game->getBoard()->getField(0, 7);
        unitPtr buff = std::make_shared<Rook>(color, field);
        pieces.push_back(buff);
        field->setUnit(buff);

        field = this->game->getBoard()->getField(7, 7);
        buff = std::make_shared<Rook>(color, field);
        pieces.push_back(buff);
        field->setUnit(buff);

        //knights
        field = this->game->getBoard()->getField(1, 7);
        buff = std::make_shared<Knight>(color, field);
        pieces.push_back(buff);
        field->setUnit(buff);

        field = this->game->getBoard()->getField(6, 7);
        buff = std::make_shared<Knight>(color, field);
        pieces.push_back(buff);
        field->setUnit(buff);


        //bishops
        field = this->game->getBoard()->getField(2, 7);
        buff = std::make_shared<Bishop>(color, field);
        pieces.push_back(buff);
        field->setUnit(buff);

        field = this->game->getBoard()->getField(5, 7);
        buff = std::make_shared<Bishop>(color, field);
        pieces.push_back(buff);
        field->setUnit(buff);

        //queen
        field = this->game->getBoard()->getField(3, 7);
        buff = std::make_shared<Queen>(color, field);
        pieces.push_back(buff);
        field->setUnit(buff);

        //king
        field = this->game->getBoard()->getField(4, 7);
        buff = std::make_shared<King>(color, field);
        pieces.push_back(buff);
        field->setUnit(buff);
        king = buff;
    }

}

Player::~Player() {

}


void Player::calculatePossibleMoves() {
    allPossibleMoves.clear();
    for(unitPtr piece : this->pieces)
    {
        allPossibleMoves.push_back(std::make_tuple<unitPtr, std::vector<fieldPtr>>(
                static_cast<shared_ptr<Unit> &&>(piece), piece->calculatePossibleMoves(this->getGame()->getBoard())));
    }
}

void Player::displayPossibleMoves() {
    for(auto tuple : allPossibleMoves)
    {
        if(!std::get<1>(tuple).empty()){
            for(const auto& move : std::get<1>(tuple)){
                std::cout<<std::get<0>(tuple)->getField()->toString()<<move->toString()<<" ";
            }
            std::cout<<std::endl;
        }

    }

}

std::tuple<unitPtr, fieldPtr> Player::getPossibleMoveFromString(const std::string& input) {
    unitPtr unit;
    fieldPtr field;
    if(input.size()!=4) throw std::invalid_argument("Argument to long");
    int fromX = (int) (input[0]-'a'), fromY = (int) (input[1]-'1');
    int toX = (int) (input[2]-'a'), toY = (int) (input[3]-'1');
    unit = this->game->getBoard()->getField(fromX, fromY)->getUnit();
    field = this->game->getBoard()->getField(toX, toY);

    if(unit != nullptr){
        //std::vector<fieldPtr> moves = std::get<1>(std::find(allPossibleMoves.begin(), allPossibleMoves.end(), unit));
        for(auto moves : allPossibleMoves){
            if(std::get<0>(moves)->getType() == unit->getType()){
                for(auto f: std::get<1>(moves)){
                    if(f->toString() == field->toString()) return std::make_tuple(unit, field);
                }
            }

        }
        //cout<<moves.size();
    }
    throw std::invalid_argument("Move not possible");

}

std::tuple<unitPtr, fieldPtr, fieldPtr, unitPtr> Player::makeMove(std::tuple<unitPtr, fieldPtr> m) {
    fieldPtr field = std::get<0>(m)->getField();
    unitPtr buff = this->getGame()->getBoard()->move(std::get<0>(m)->getField(), std::get<1>(m));

    return std::make_tuple(std::get<0>(m), field, std::get<1>(m), buff);
}

bool Player::canMove(const fieldPtr& field) {
    for(auto moves : allPossibleMoves){
        for(const auto& f: std::get<1>(moves)){
            if(f->toString() == field->toString()) return true;
        }
    }
    return false;
}

bool Player::isChecked() {
    return this->game->getOtherPlayer()->canMove(this->king->getField());
}


