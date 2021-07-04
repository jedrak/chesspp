//
// Created by Andrzej on 7/4/2021.
//

#include "Bishop.h"
#include "Board.h"
#include "Game.h"
#include <boost/test/unit_test.hpp>
#include <Pawn.h>

BOOST_AUTO_TEST_SUITE(PawnMovementSuite)

    BOOST_AUTO_TEST_CASE(PawnCalculateFirstMove)
    {
        boardPtr board = std::make_shared<Board>();
        unitPtr pawnW = std::make_shared<Pawn>(Pawn('W', nullptr));

        board->getField(0, 1)->setUnit(pawnW);
        pawnW->setField( board->getField(0, 1));
        std::vector<fieldPtr> moves = pawnW->calculatePossibleMoves(board);

        unitPtr pawnB = std::make_shared<Pawn>(Pawn('B', nullptr));

        board->getField(0, 6)->setUnit(pawnB);
        pawnB->setField( board->getField(0, 6));
        board->display();
        //std::vector<fieldPtr> moves = pawnB->calculatePossibleMoves(board);

        std::stringstream ss;
        for(fieldPtr field:moves)
        {
            ss<<field->toString()<<" ";
        }
        BOOST_REQUIRE_EQUAL(ss.str(), "a4 a3 ");
        moves = pawnB->calculatePossibleMoves(board);

        std::stringstream ss1;
        for(fieldPtr field:moves)
        {
            ss1<<field->toString()<<" ";
        }
        BOOST_REQUIRE_EQUAL(ss1.str(), "a5 a6 ");
    }

    BOOST_AUTO_TEST_CASE(PawnCalculateNormalMove)
    {
        boardPtr board = std::make_shared<Board>();
        unitPtr pawnW = std::make_shared<Pawn>(Pawn('W', nullptr));

        board->getField(0, 2)->setUnit(pawnW);
        pawnW->setField( board->getField(0, 2));
        std::vector<fieldPtr> moves = pawnW->calculatePossibleMoves(board);

        unitPtr pawnB = std::make_shared<Pawn>(Pawn('B', nullptr));

        board->getField(0, 5)->setUnit(pawnB);
        pawnB->setField( board->getField(0, 5));
        board->display();
        //std::vector<fieldPtr> moves = pawnB->calculatePossibleMoves(board);

        std::stringstream ss;
        for(fieldPtr field:moves)
        {
            ss<<field->toString()<<" ";
        }
        BOOST_REQUIRE_EQUAL(ss.str(), "a4 ");
        moves = pawnB->calculatePossibleMoves(board);

        std::stringstream ss1;
        for(fieldPtr field:moves)
        {
            ss1<<field->toString()<<" ";
        }
        BOOST_REQUIRE_EQUAL(ss1.str(), "a5 ");
    }

    BOOST_AUTO_TEST_CASE(PawnCalculateTaking)
    {
        boardPtr board = std::make_shared<Board>();
        unitPtr pawnW = std::make_shared<Pawn>(Pawn('W', nullptr));

        board->getField(0, 2)->setUnit(pawnW);
        pawnW->setField( board->getField(0, 2));


        unitPtr pawnB = std::make_shared<Pawn>(Pawn('B', nullptr));

        board->getField(1, 3)->setUnit(pawnB);
        pawnB->setField( board->getField(1, 3));
        board->display();
        //std::vector<fieldPtr> moves = pawnB->calculatePossibleMoves(board);
        std::vector<fieldPtr> moves = pawnW->calculatePossibleMoves(board);
        std::stringstream ss;
        for(const fieldPtr& field:moves)
        {
            ss<<field->toString()<<" ";
        }
        BOOST_REQUIRE_EQUAL(ss.str(), "a4 b4 ");
        moves = pawnB->calculatePossibleMoves(board);

        std::stringstream ss1;
        for(const fieldPtr& field:moves)
        {
            ss1<<field->toString()<<" ";
        }
        BOOST_REQUIRE_EQUAL(ss1.str(), "b3 a3 ");
    }

BOOST_AUTO_TEST_SUITE_END()