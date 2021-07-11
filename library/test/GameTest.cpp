#include <boost/test/unit_test.hpp>
#include <Player.h>
#include <Game.h>
#include <memory>
using namespace std;


void print(const unitPtr &unit) {
    cout << unit->getColour() << unit->getType();
}

bool cliObserver(boardPtr board) {
    cout << endl << "   a  b  c  d  e  f  g  h" << endl;
    cout << " -------------------------" << endl;
    for (int y = 7; y >= 0; y--) {
        cout << y + 1;
        for (int x = 0; x < 8; x++) {
            cout << "|";
            if (board->getField(x,y)->occupied())
                print(board->getField(x,y)->getUnit());
            else
                cout << "  ";
        }
        cout << "|" << y + 1 << endl << " -------------------------" << endl;
    }
    cout << "   a  b  c  d  e  f  g  h" << endl << endl;

    return false;
}


class CLIObserver: public Observer
{
public:
    bool notify(boardPtr board) {
        return cliObserver(board);
    }
};

BOOST_AUTO_TEST_SUITE(PlayerSuite)

    BOOST_AUTO_TEST_CASE(IsCheckedTest)
    {
        gamePtr game = make_shared<Game>(std::make_shared<CLIObserver>());
        game->initialize();
        game->getBoard()->display();

        game->getActivePlayer()->makeMove(make_tuple(game->getBoard()->getField(4, 1)->getUnit(), game->getBoard()->getField(4, 3)));
        game->getBoard()->display();
        game->getActivePlayer()->calculatePossibleMoves();
        game->getNextPlayer()->calculatePossibleMoves();
        game->getNextPlayer()->makeMove(make_tuple(game->getBoard()->getField(5, 6)->getUnit(), game->getBoard()->getField(5, 4)));
        game->getBoard()->display();
        game->getActivePlayer()->calculatePossibleMoves();
        game->getNextPlayer()->calculatePossibleMoves();
        game->getActivePlayer()->makeMove(make_tuple(game->getBoard()->getField(3, 0)->getUnit(), game->getBoard()->getField(7, 4)));
        game->getBoard()->display();
        game->getActivePlayer()->calculatePossibleMoves();
        game->getNextPlayer()->calculatePossibleMoves();

        std::cout<<game->getActivePlayer()->getName()<<std::endl;
        for(auto piece : game->getActivePlayer()->getAllPossibleMoves())
        {

            if(std::get<0>(piece)->getType() == 'Q' )for(auto move : std::get<1>(piece))
            {
                std::cout<<move->toString()<<std::endl;
            }
        }

        std::cout<<game->getNextPlayer()->getName()<<std::endl;
        for(auto piece : game->getNextPlayer()->getAllPossibleMoves())
        {
            if(std::get<0>(piece)->getType() == 'Q')for(auto move : std::get<1>(piece))
                {
                    std::cout<<move->toString()<<std::endl;
                }
        }
        BOOST_REQUIRE_EQUAL(game->getNextPlayer()->getKing()->getField()->occupied(), true);

        BOOST_REQUIRE_EQUAL(game->getBoard()->getField(7, 4)->occupied(), true);

        BOOST_REQUIRE_EQUAL(game->getNextPlayer()->getName(), "Black");
        BOOST_REQUIRE_EQUAL(game->getNextPlayer()->isChecked(), true);

    }


    BOOST_AUTO_TEST_CASE(revertMoveTest)
    {
        gamePtr game = make_shared<Game>(std::make_shared<CLIObserver>());
        game->initialize();
        game->getBoard()->display();

        game->getActivePlayer()->makeMove(make_tuple(game->getBoard()->getField(4, 1)->getUnit(), game->getBoard()->getField(4, 3)));
        game->getBoard()->display();
        game->getActivePlayer()->calculatePossibleMoves();
        game->getNextPlayer()->calculatePossibleMoves();

        game->getNextPlayer()->makeMove(make_tuple(game->getBoard()->getField(5, 6)->getUnit(), game->getBoard()->getField(5, 4)));
        game->getBoard()->display();
        game->getActivePlayer()->calculatePossibleMoves();
        game->getNextPlayer()->calculatePossibleMoves();

        auto lastMove = game->getActivePlayer()->makeMove(make_tuple(game->getBoard()->getField(4, 3)->getUnit(), game->getBoard()->getField(5, 4)));
        game->getBoard()->display();
        game->getActivePlayer()->calculatePossibleMoves();
        game->getNextPlayer()->calculatePossibleMoves();

        game->revertMove(lastMove);
        game->getBoard()->display();
    }


    BOOST_AUTO_TEST_CASE(takingWhite)
    {
        gamePtr game = make_shared<Game>(std::make_shared<CLIObserver>());
        game->initialize();
        game->getBoard()->display();

        game->getActivePlayer()->makeMove(make_tuple(game->getBoard()->getField(4, 1)->getUnit(), game->getBoard()->getField(4, 3)));
        game->getBoard()->display();
        game->getActivePlayer()->calculatePossibleMoves();
        game->getNextPlayer()->calculatePossibleMoves();

        game->getNextPlayer()->makeMove(make_tuple(game->getBoard()->getField(5, 6)->getUnit(), game->getBoard()->getField(5, 4)));
        game->getBoard()->display();
        game->getActivePlayer()->calculatePossibleMoves();
        game->getNextPlayer()->calculatePossibleMoves();

        auto lastMove = game->getNextPlayer()->makeMove(make_tuple(game->getBoard()->getField(5, 4)->getUnit(), game->getBoard()->getField(4, 3)));
        game->getBoard()->display();
        game->getActivePlayer()->calculatePossibleMoves();
        game->getNextPlayer()->calculatePossibleMoves();

        BOOST_REQUIRE_EQUAL(game->getActivePlayer()->getName(), "White");
        BOOST_REQUIRE_EQUAL(game->getNextPlayer()->getName(), "Black");
        BOOST_REQUIRE_EQUAL(game->getActivePlayer()->getPiecesNumber(), 15);
        BOOST_REQUIRE_EQUAL(game->getNextPlayer()->getPiecesNumber(), 16);

    }

    BOOST_AUTO_TEST_CASE(takingBlack)
    {
        gamePtr game = make_shared<Game>(std::make_shared<CLIObserver>());
        game->initialize();
        game->getBoard()->display();

        game->getActivePlayer()->makeMove(make_tuple(game->getBoard()->getField(4, 1)->getUnit(), game->getBoard()->getField(4, 3)));
        game->getBoard()->display();
        game->getActivePlayer()->calculatePossibleMoves();
        game->getNextPlayer()->calculatePossibleMoves();

        game->getNextPlayer()->makeMove(make_tuple(game->getBoard()->getField(5, 6)->getUnit(), game->getBoard()->getField(5, 4)));
        game->getBoard()->display();
        game->getActivePlayer()->calculatePossibleMoves();
        game->getNextPlayer()->calculatePossibleMoves();

        auto lastMove = game->getActivePlayer()->makeMove(make_tuple(game->getBoard()->getField(4, 3)->getUnit(), game->getBoard()->getField(5, 4)));
        game->getBoard()->display();
        game->getActivePlayer()->calculatePossibleMoves();
        game->getNextPlayer()->calculatePossibleMoves();

        BOOST_REQUIRE_EQUAL(game->getActivePlayer()->getName(), "White");
        BOOST_REQUIRE_EQUAL(game->getNextPlayer()->getName(), "Black");
        BOOST_REQUIRE_EQUAL(game->getNextPlayer()->getPiecesNumber(), 15);
        BOOST_REQUIRE_EQUAL(game->getActivePlayer()->getPiecesNumber(), 16);

    }

BOOST_AUTO_TEST_SUITE_END()