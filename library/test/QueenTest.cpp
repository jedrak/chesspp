//
// Created by Andrzej on 7/4/2021.
//

#include "Bishop.h"
#include "Board.h"
#include "Game.h"
#include <boost/test/unit_test.hpp>
#include <Queen.h>

BOOST_AUTO_TEST_SUITE(QueenMovementSuite)

    BOOST_AUTO_TEST_CASE(QueenCalculateA1)
    {
        boardPtr board = std::make_shared<Board>();
        unitPtr queen = std::make_shared<Queen>(Queen('W', nullptr));

        board->getField(0, 0)->setUnit(queen);
        queen->setField( board->getField(0, 0));
        board->display();
        std::vector<fieldPtr> moves = queen->calculatePossibleMoves(board);

        std::stringstream ss;
        for(fieldPtr field:moves)
        {
            ss<<field->toString()<<" ";
        }
        BOOST_REQUIRE_EQUAL(ss.str(), "b1 c1 d1 e1 f1 g1 h1 a2 a3 a4 a5 a6 a7 a8 b2 c3 d4 e5 f6 g7 h8 ");
    }

    BOOST_AUTO_TEST_CASE(QueenCalculateH8)
    {
        boardPtr board = std::make_shared<Board>();
        unitPtr queen = std::make_shared<Queen>(Queen('W', nullptr));

        board->getField(7, 7)->setUnit(queen);
        queen->setField( board->getField(7, 7));
        board->display();
        std::vector<fieldPtr> moves = queen->calculatePossibleMoves(board);

        std::stringstream ss;
        for(fieldPtr field:moves)
        {
            ss<<field->toString()<<" ";
        }
        BOOST_REQUIRE_EQUAL(ss.str(), "g8 f8 e8 d8 c8 b8 a8 h7 h6 h5 h4 h3 h2 h1 g7 f6 e5 d4 c3 b2 a1 ");
    }

BOOST_AUTO_TEST_SUITE_END()