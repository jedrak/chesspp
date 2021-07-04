//
// Created by Andrzej on 7/4/2021.
//


#include "Board.h"
#include "Game.h"
#include <boost/test/unit_test.hpp>
#include <Knight.h>
#include <King.h>

BOOST_AUTO_TEST_SUITE(KingMovementSuite)

    BOOST_AUTO_TEST_CASE(KingCalculateA1)
    {
        boardPtr board = std::make_shared<Board>();
        unitPtr king = std::make_shared<King>(King('W', nullptr));

        board->getField(0, 0)->setUnit(king);
        king->setField( board->getField(0, 0));
        board->display();
        std::vector<fieldPtr> moves = king->calculatePossibleMoves(board);

        std::stringstream ss;
        for(const fieldPtr& field:moves)
        {
            ss<<field->toString()<<" ";
        }
        BOOST_REQUIRE_EQUAL(ss.str(), "b1 a2 b2 ");
    }

    BOOST_AUTO_TEST_CASE(KingCalculateC3)
    {
        boardPtr board = std::make_shared<Board>();
        unitPtr king = std::make_shared<King>(King('W', nullptr));

        board->getField(2, 2)->setUnit(king);
        king->setField( board->getField(2, 2));
        board->display();
        std::vector<fieldPtr> moves = king->calculatePossibleMoves(board);

        std::stringstream ss;
        for(const fieldPtr& field:moves)
        {
            ss<<field->toString()<<" ";
        }
        BOOST_REQUIRE_EQUAL(ss.str(), "d3 b3 c2 c4 d4 b4 d2 b2 ");
    }

BOOST_AUTO_TEST_SUITE_END()