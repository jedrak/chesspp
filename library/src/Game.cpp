#include "Game.h"
#include "Bishop.h"

void Game::initialize() {
    this->board = std::make_shared<Board>();
    bishopPtr newBishop = std::make_shared<Bishop>(Bishop('W', nullptr));
    this->board->getField(4, 4)->setUnit(newBishop);

}

playerPtr Game::getNextPlayer() {
    return nullptr;
}

Game::~Game() {

}

const boardPtr &Game::getBoard() const {
    return board;
}

void Game::simulate() {
    board->display();

}

Game::Game() {}

