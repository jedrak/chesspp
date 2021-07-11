#include "Game.h"
#include <iostream>

using namespace std;

void Game::initialize() {
    this->board = make_shared<Board>();
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
    }
    else
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
    if (getObserver() != nullptr) {
        getObserver()->notify(getBoard());
    }

    while(true)
    {
        std::string input;

        std::cout<<"it's "<<activePlayer->getName()<<" turn"<<std::endl;
        std::cin>>input;
        try
        {
            activePlayer->makeMove(activePlayer->getPossibleMoveFromString(input), false);

            activePlayer = getNextPlayer();

            activePlayer->calculatePossibleMoves();
            getNextPlayer()->calculatePossibleMoves();
            activePlayer->deleteIllegalMoves();
            getNextPlayer()->deleteIllegalMoves();

            if (getObserver() != nullptr) {
                getObserver()->notify(getBoard());
            }
            if(activePlayer->isChecked()) std::cout<< "Player " << activePlayer->getName()<<" is checked";
            if(activePlayer->getNumberOfMoves() == 0)
            {
                if(activePlayer->isChecked())
                {
                    std::cout<<" and mated." <<std::endl;
                    std::cout<<"Player "<< getNextPlayer()->getName()<<" has won."<<std::endl;
                }
                else
                {
                    std::cout<<"Player has tied"<<std::endl;
                }
                break;
            }
            else if(activePlayer->isChecked())
            {
                std::cout<<"."<<std::endl;
            }

        } catch (std::invalid_argument& ia) {

            std::cerr << "Invalid argument: " << ia.what() << '\n';
            activePlayer->displayPossibleMoves();

        }
    }
}

Game::Game(const observerPtr &observer) : observer(observer) {
    player1 = std::make_shared<Player>(Player("White", std::shared_ptr<Game>(this), 'W'));
    player2 = std::make_shared<Player>(Player("Black", std::shared_ptr<Game>(this), 'B'));
}

void Game::revertMove(std::tuple<unitPtr, fieldPtr, fieldPtr, unitPtr> lastMove) {
    //board->display();
    unitPtr mover = std::get<0>(lastMove), taker = std::get<3>(lastMove);
    fieldPtr from = std::get<1>(lastMove), to = std::get<2>(lastMove);
    board->move(to,from);
    from->setUnit(mover);
    if(taker) {
        taker->setField(to);
        to->setUnit(taker);
    }
    //board->display();
}

const observerPtr &Game::getObserver() const {
    return observer;
}

const playerPtr &Game::getActivePlayer() const {
    return activePlayer;
}
