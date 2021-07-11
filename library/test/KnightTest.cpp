#include "Bishop.h"
#include "Board.h"
#include "Game.h"
#include <boost/test/unit_test.hpp>
#include <Knight.h>

BOOST_AUTO_TEST_SUITE(KnightMovementSuite)

    BOOST_AUTO_TEST_CASE(KingCalculateA1)
    {
        boardPtr board = std::make_shared<Board>();
        unitPtr knight = std::make_shared<Knight>(Knight('W', nullptr));

        board->getField(0, 0)->setUnit(knight);
        knight->setField( board->getField(0, 0));
        board->display();
        std::vector<fieldPtr> moves = knight->calculatePossibleMoves(board);

        std::stringstream ss;
        for(fieldPtr field:moves)
        {
            ss<<field->toString()<<" ";
        }
        BOOST_REQUIRE_EQUAL(ss.str(), "c2 b3 ");
    }


    BOOST_AUTO_TEST_CASE(KnightCalculateH8)
    {
        boardPtr board = std::make_shared<Board>();
        unitPtr knight = std::make_shared<Knight>(Knight('W', nullptr));

        board->getField(7, 7)->setUnit(knight);
        knight->setField( board->getField(7, 7));
        board->display();
        std::vector<fieldPtr> moves = knight->calculatePossibleMoves(board);

        std::stringstream ss;
        for(fieldPtr field:moves)
        {
            ss<<field->toString()<<" ";
        }
        BOOST_REQUIRE_EQUAL(ss.str(), "f7 g6 ");
    }

    BOOST_AUTO_TEST_CASE(KnightCalculateA8)
    {
        boardPtr board = std::make_shared<Board>();
        unitPtr knight = std::make_shared<Knight>(Knight('W', nullptr));

        board->getField(0, 7)->setUnit(knight);
        knight->setField( board->getField(0, 7));
        board->display();
        std::vector<fieldPtr> moves = knight->calculatePossibleMoves(board);

        std::stringstream ss;
        for(fieldPtr field:moves)
        {
            ss<<field->toString()<<" ";
        }
        BOOST_REQUIRE_EQUAL(ss.str(), "c7 b6 ");
    }

    BOOST_AUTO_TEST_CASE(KnightCalculateH1)
    {
        boardPtr board = std::make_shared<Board>();
        unitPtr knight = std::make_shared<Knight>(Knight('W', nullptr));

        board->getField(7, 0)->setUnit(knight);
        knight->setField( board->getField(7, 0));
        board->display();
        std::vector<fieldPtr> moves = knight->calculatePossibleMoves(board);

        std::stringstream ss;
        for(fieldPtr field:moves)
        {
            ss<<field->toString()<<" ";
        }
        BOOST_REQUIRE_EQUAL(ss.str(), "f2 g3 ");
    }


    BOOST_AUTO_TEST_CASE(KnightCalculateOcuupiedField)
    {
        boardPtr board = std::make_shared<Board>();
        unitPtr knight = std::make_shared<Knight>(Knight('W', nullptr));
        board->getField(0, 0)->setUnit(knight);
        knight->setField( board->getField(0, 0));

        unitPtr knight1 = std::make_shared<Knight>(Knight('W', nullptr));
        board->getField(1, 2)->setUnit(knight1);
        knight1->setField( board->getField(1, 2));

        unitPtr knight2 = std::make_shared<Knight>(Knight('B', nullptr));
        board->getField(2, 1)->setUnit(knight2);
        knight2->setField( board->getField(2, 1));

        board->display();
        std::vector<fieldPtr> moves = knight->calculatePossibleMoves(board);

        std::stringstream ss;
        for(fieldPtr field:moves)
        {
            ss<<field->toString()<<" ";
        }
        BOOST_REQUIRE_EQUAL(ss.str(), "c2 ");
    }

BOOST_AUTO_TEST_SUITE_END()