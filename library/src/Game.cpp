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

        std::cout<<"it's "<<activePlayer->getName()<<" turn"<<std::endl;
        std::cin>>input;
        try
        {
            activePlayer->makeMove(activePlayer->getPossibleMoveFromString(input));

            activePlayer = getOtherPlayer();

            player1->calculatePossibleMoves();
            player2->calculatePossibleMoves();

            //player1->deleteIllegalMoves();
            //player2->deleteIllegalMoves();
            board->display();
            if(activePlayer->isChecked()) std::cout<< "Player " << activePlayer->getName()<<" is checked"<<std::endl;

        } catch (std::invalid_argument& ia) {

            std::cerr << "Invalid argument: " << ia.what() << '\n';
            activePlayer->displayPossibleMoves();

        }


    }



}

Game::Game() {
    player1 = std::make_shared<Player>(Player("White", std::shared_ptr<Game>(this), 'W'));
    player2 = std::make_shared<Player>(Player("Black", std::shared_ptr<Game>(this), 'B'));
}

void Game::revertMove(std::tuple<unitPtr, fieldPtr, fieldPtr, unitPtr> lastMove) {
    unitPtr mover = std::get<0>(lastMove), taker = std::get<3>(lastMove);
    fieldPtr from = std::get<1>(lastMove), to = std::get<2>(lastMove);
    board->move(to,from);
    from->setUnit(mover);
    if(taker) {
        taker->setField(to);
        to->setUnit(taker);
    }


}

