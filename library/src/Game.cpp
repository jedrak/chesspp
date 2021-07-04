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

playerPtr Game::getOtherPlayer() {
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
            lastMove = activePlayer->makeMove(activePlayer->getPossibleMoveFromString(input));
            board->display();
            activePlayer = getOtherPlayer();

            player1->calculatePossibleMoves();
            player2->calculatePossibleMoves();
            if(activePlayer->isChecked()) std::cout<< "Player " << activePlayer->getGame()<<" is checked"<<std::endl;

        } catch (std::invalid_argument& ia) {
            if(input == "r"){
                std::cout<<"Reverting move"<<std::endl;
                revertMove();
                board->display();
            }else{
                std::cerr << "Invalid argument: " << ia.what() << '\n';
                activePlayer->displayPossibleMoves();
            }

        }


    }



}

Game::Game() {
    player1 = std::make_shared<Player>(Player("player1", std::shared_ptr<Game>(this), 'W'));
    player2 = std::make_shared<Player>(Player("player2", std::shared_ptr<Game>(this), 'B'));
}

void Game::revertMove() {
    unitPtr mover = std::get<0>(lastMove), taker = std::get<3>(lastMove);
    fieldPtr from = std::get<1>(lastMove), to = std::get<2>(lastMove);
    board->move(to,from);
    from->setUnit(mover);
    if(taker) {
        taker->setField(to);
        to->setUnit(taker);
    }


}

