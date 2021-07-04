//
// Created by Andrzej on 7/4/2021.
//

#include "Bishop.h"
#include "Board.h"
#include "Game.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(BishopMovementSuite)

   BOOST_AUTO_TEST_CASE(BishopCalculateA1)
    {
        boardPtr board = std::make_shared<Board>();
        bishopPtr newBishop = std::make_shared<Bishop>(Bishop('W', nullptr));

        board->getField(0, 0)->setUnit(newBishop);
        newBishop->setField( board->getField(0, 0));
        board->display();
        std::vector<fieldPtr> moves = newBishop->calculatePossibleMoves(board);

        std::stringstream ss;
        for(fieldPtr field:moves)
        {
            ss<<field->toString()<<" ";
        }
        BOOST_REQUIRE_EQUAL(ss.str(), "b2 c3 d4 e5 f6 g7 h8 ");
    }


    BOOST_AUTO_TEST_CASE(BishopCalculateH1)
    {
        boardPtr board = std::make_shared<Board>();
        bishopPtr newBishop = std::make_shared<Bishop>(Bishop('W', nullptr));

        board->getField(7, 0)->setUnit(newBishop);
        newBishop->setField( board->getField(7, 0));
        board->display();
        std::vector<fieldPtr> moves = newBishop->calculatePossibleMoves(board);

        std::stringstream ss;
        for(fieldPtr field:moves)
        {
            ss<<field->toString()<<" ";
        }
        BOOST_REQUIRE_EQUAL(ss.str(), "g2 f3 e4 d5 c6 b7 a8 ");
    }

    BOOST_AUTO_TEST_CASE(BishopCalculateA8)
    {
        boardPtr board = std::make_shared<Board>();
        bishopPtr newBishop = std::make_shared<Bishop>(Bishop('W', nullptr));

        board->getField(0, 7)->setUnit(newBishop);
        newBishop->setField( board->getField(0, 7));
        board->display();
        std::vector<fieldPtr> moves = newBishop->calculatePossibleMoves(board);

        std::stringstream ss;
        for(fieldPtr field:moves)
        {
            ss<<field->toString()<<" ";
        }
        BOOST_REQUIRE_EQUAL(ss.str(), "b7 c6 d5 e4 f3 g2 h1 ");
    }

    BOOST_AUTO_TEST_CASE(BishopCalculateH8)
    {
        boardPtr board = std::make_shared<Board>();
        bishopPtr newBishop = std::make_shared<Bishop>(Bishop('W', nullptr));

        board->getField(7, 7)->setUnit(newBishop);
        newBishop->setField( board->getField(7, 7));
        board->display();
        std::vector<fieldPtr> moves = newBishop->calculatePossibleMoves(board);

        std::stringstream ss;
        for(fieldPtr field:moves)
        {
            ss<<field->toString()<<" ";
        }
        BOOST_REQUIRE_EQUAL(ss.str(), "g7 f6 e5 d4 c3 b2 a1 ");
    }


    BOOST_AUTO_TEST_CASE(BishopCalculateD4)
    {
        boardPtr board = std::make_shared<Board>();
        bishopPtr newBishop = std::make_shared<Bishop>(Bishop('W', nullptr));

        board->getField(3, 3)->setUnit(newBishop);
        newBishop->setField( board->getField(3, 3));
        board->display();
        std::vector<fieldPtr> moves = newBishop->calculatePossibleMoves(board);

        std::stringstream ss;
        for(fieldPtr field:moves)
        {
            ss<<field->toString()<<" ";
        }
        BOOST_REQUIRE_EQUAL(ss.str(), "e5 f6 g7 h8 c5 b6 a7 e3 f2 g1 c3 b2 a1 ");
    }

    BOOST_AUTO_TEST_CASE(BishopCalculateTwoBishopsDiffColors)
    {
        boardPtr board = std::make_shared<Board>();
        bishopPtr Bishop1 = std::make_shared<Bishop>(Bishop('W', nullptr));
        board->getField(0, 0)->setUnit(Bishop1);
        Bishop1->setField( board->getField(0, 0));

        bishopPtr Bishop2 = std::make_shared<Bishop>(Bishop('B', nullptr));
        board->getField(7, 7)->setUnit(Bishop2);
        Bishop2->setField( board->getField(7, 7));

        board->display();
        std::vector<fieldPtr> moves = Bishop1->calculatePossibleMoves(board);

        std::stringstream ss;
        for(fieldPtr field:moves)
        {
            ss<<field->toString()<<" ";
        }
        BOOST_REQUIRE_EQUAL(ss.str(), "b2 c3 d4 e5 f6 g7 h8 ");
        moves = Bishop2->calculatePossibleMoves(board);

        std::stringstream ss1;
        for(fieldPtr field:moves)
        {
            ss1<<field->toString()<<" ";
        }
        BOOST_REQUIRE_EQUAL(ss1.str(), "g7 f6 e5 d4 c3 b2 a1 ");
    }

    BOOST_AUTO_TEST_CASE(BishopCalculateTwoBishopsSameColor)
    {
        boardPtr board = std::make_shared<Board>();
        bishopPtr Bishop1 = std::make_shared<Bishop>(Bishop('W', nullptr));
        board->getField(0, 0)->setUnit(Bishop1);
        Bishop1->setField( board->getField(0, 0));

        bishopPtr Bishop2 = std::make_shared<Bishop>(Bishop('W', nullptr));
        board->getField(7, 7)->setUnit(Bishop2);
        Bishop2->setField( board->getField(7, 7));

        board->display();
        std::vector<fieldPtr> moves = Bishop1->calculatePossibleMoves(board);

        std::stringstream ss;
        for(fieldPtr field:moves)
        {
            ss<<field->toString()<<" ";
        }
        BOOST_REQUIRE_EQUAL(ss.str(), "b2 c3 d4 e5 f6 g7 ");
        moves = Bishop2->calculatePossibleMoves(board);

        std::stringstream ss1;
        for(fieldPtr field:moves)
        {
            ss1<<field->toString()<<" ";
        }
        BOOST_REQUIRE_EQUAL(ss1.str(), "g7 f6 e5 d4 c3 b2 ");
    }

BOOST_AUTO_TEST_SUITE_END()