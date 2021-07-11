#include "Game.h"
#include "Player.h"
#include "Board.h"
#include "Unit.h"
#include <iostream>
#include <utility>
#include <sstream>
#include <algorithm>

using namespace std;

std::string Player::getName() const {
    return name;
}

 Player::~Player() {
    allPossibleMoves.clear();
    pieces.clear();
 }

const gamePtr &Player::getGame() const {
    return game;
}

Player::Player(string name, gamePtr game, char color) : name(std::move(name)), game(std::move(game)), color(color) {
    pieces = std::vector<unitPtr>();
    allPossibleMoves = std::vector<std::tuple<unitPtr, std::vector<fieldPtr>>>();
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
        for(auto moves : allPossibleMoves){
            if(std::get<0>(moves)->getType() == unit->getType()){
                for(auto f: std::get<1>(moves)){
                    if(f->toString() == field->toString()) return std::make_tuple(unit, field);
                }
            }

        }
    }
    throw std::invalid_argument("Move not possible");

}

std::tuple<unitPtr, fieldPtr, fieldPtr, unitPtr> Player::makeMove(std::tuple<unitPtr, fieldPtr> m, bool mock) {
    fieldPtr field = std::get<0>(m)->getField();
    unitPtr buff = this->getGame()->getBoard()->move(std::get<0>(m)->getField(), std::get<1>(m));

    if(buff!= nullptr && !mock){
        //std::cout<<buff->getColour()<<buff->getType()<<" "<< buff<<std::endl;
        for(auto it = getOtherPlayer(getName())->pieces.begin(); it!=getOtherPlayer(getName())->pieces.end();){
            //std::cout<<it->get()->getColour()<<it->get()->getType()<<" "<< it->get()<<std::endl;
            if(*it == buff){
                it = getOtherPlayer(getName())->pieces.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }

    return std::make_tuple(std::get<0>(m), field, std::get<1>(m), buff);
}

bool Player::canMove(const fieldPtr& field) {
    for(auto moves : allPossibleMoves){
        for(const auto& f: std::get<1>(moves)){
            //std::cout<<f->toString()<<" "<<field->toString()<<" "<<(f->toString() == field->toString())<<std::endl;
            if(f->toString() == field->toString()) return true;
        }
    }
    return false;
}

bool Player::isChecked() {
    //cout<< "Calculating if player "<< this->getName()<< "is checked"<<std::endl;
    return this->getOtherPlayer(name)->canMove(this->king->getField());
}

void Player::deleteIllegalMoves() {

    auto possibleMoves = allPossibleMoves;
    auto otherPossibleMovesBuff = this->getOtherPlayer(getName())->allPossibleMoves;
    for(int i = 0; i < possibleMoves.size(); i++){
        std::vector<fieldPtr> legal;
        for(auto f: std::get<1>(possibleMoves[i])){
            auto lastMove = this->makeMove(std::make_tuple(std::get<0>(possibleMoves[i]), f), true);
            this->calculatePossibleMoves();
            this->getOtherPlayer(getName())->calculatePossibleMoves();

            std::cout<<isChecked()<<std::endl;
            if(!this->isChecked()) legal.push_back(f);
            else std::cout<<"not legal";
            this->getGame()->revertMove(lastMove);
        }
        std::get<1>(possibleMoves[i]) = legal;

    }
    allPossibleMoves = possibleMoves;


    this->getOtherPlayer(getName())->allPossibleMoves = otherPossibleMovesBuff;
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

const unitPtr &Player::getKing() const {
    return king;
}

const vector<std::tuple<unitPtr, std::vector<fieldPtr>>> &Player::getAllPossibleMoves() const {
    return allPossibleMoves;
}

playerPtr Player::getOtherPlayer(std::string name) {
    return game->getActivePlayer()->getName() == name ? game->getNextPlayer() : game->getActivePlayer();
}

int Player::getNumberOfMoves() {
    int buff =0;
    for(auto moves : allPossibleMoves)
    {
        buff += std::get<1>(moves).size();
    }
    return buff;
}

int Player::getPiecesNumber() {
    return pieces.size();
}

