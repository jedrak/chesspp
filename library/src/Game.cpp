#include <iostream>
#include "Game.h"
#include "Bishop.h"

void Game::initialize() {
    this->board = std::make_shared<Board>();
    this->activePlayer = player1;
    this->player1->setup();
    this->player2->setup();

    this->player1->calculatePossibleMoves();
    this->player2->calculatePossibleMoves();


}

playerPtr Game::getNextPlayer() {
    if(activePlayer == player1)
    {
        return player2;
    }else
    {
        return player1;
    }
}

Game::~Game() {

}

const boardPtr &Game::getBoard() const {
    return board;
}

void Game::simulate() {
    board->display();
    //player1->displayPossibleMoves();
    //player2->displayPossibleMoves();

    while(true)
    {
        std::string input;
        std::cin>>input;
        try
        {
            activePlayer->makeMove(activePlayer->getPossibleMoveFromString(input));
            board->display();

            activePlayer = getNextPlayer();
            player1->calculatePossibleMoves();
            player2->calculatePossibleMoves();


        } catch (std::invalid_argument& ia) {
            std::cerr << "Invalid argument: " << ia.what() << '\n';
            activePlayer->displayPossibleMoves();
        }


    }



}

Game::Game() {
    player1 = std::make_shared<Player>(Player("player1", std::shared_ptr<Game>(this), 'W'));
    player2 = std::make_shared<Player>(Player("player2", std::shared_ptr<Game>(this), 'B'));
}

