#include "Direction.hpp"
#include "doctest.h"
#include "Board.hpp"
#include <string>
using namespace std;
using ariel::Direction;


ariel::Board board;



TEST_CASE("read empty bord")
{
    CHECK(board.read(0,0, Direction::Horizontal, 5) == string("_____"));
    CHECK(board.read(0,0, Direction::Vertical, 5) == string("_____"));

}

TEST_CASE("read length 0"){
    CHECK(board.read(0,0, Direction::Horizontal, 0) == string(""));
    CHECK(board.read(0,0, Direction::Vertical, 0) == string(""));

}

TEST_CASE("post and then read Horizontal(not empty)"){
    board.post(0, 0, Direction::Horizontal,"t");
    CHECK(board.read(0,0, Direction::Horizontal, 1) == string("t"));

    board.post(0, 1, Direction::Horizontal,"e");
    CHECK(board.read(0,0, Direction::Horizontal, 2) == string("te"));

    board.post(0, 2, Direction::Horizontal,"h");
    CHECK(board.read(0,0, Direction::Horizontal, 3) == string("teh"));

    board.post(0, 3, Direction::Horizontal,"i");
    CHECK(board.read(0,0, Direction::Horizontal, 4) == string("tehi"));

    board.post(0, 4, Direction::Horizontal,"l");
    CHECK(board.read(0,0, Direction::Horizontal, 5) == string("tehil"));

    board.post(0, 5, Direction::Horizontal,"a");
    CHECK(board.read(0,0, Direction::Horizontal, 6) == string("tehila"));
}

    TEST_CASE("override and then read"){
    board.post(0, 0, Direction::Horizontal,"a");
    CHECK(board.read(0,0, Direction::Horizontal, 6) == string("aehila"));

    board.post(0, 1, Direction::Horizontal,"l");
    CHECK(board.read(0,0, Direction::Horizontal, 6) == string("alhila"));

    board.post(0, 2, Direction::Horizontal,"i");
    CHECK(board.read(0,0, Direction::Horizontal, 6) == string("aliila"));

    board.post(0, 3, Direction::Horizontal,"h");
    CHECK(board.read(0,0, Direction::Horizontal, 6) == string("alihla"));

    board.post(0, 4, Direction::Horizontal,"e");
    CHECK(board.read(0,0, Direction::Horizontal, 6) == string("alihea"));

    board.post(0, 5, Direction::Horizontal,"t");
    CHECK(board.read(0,0, Direction::Horizontal, 6) == string("alihet"));
}


TEST_CASE("read mor than length"){
    CHECK(board.read(0,0, Direction::Horizontal, 11) == string("alihet_____"));
}


TEST_CASE("read in place bigger than size"){
    CHECK(board.read(0,6, Direction::Horizontal, 5) == string("_____"));
}

TEST_CASE("post and then read Vertical(not empty)"){
    board.post(0, 0, Direction::Vertical,"t");
    CHECK(board.read(0,0, Direction::Vertical, 1) == string("t"));

    board.post(1, 0, Direction::Vertical,"e");
    CHECK(board.read(0,0, Direction::Vertical, 2) == string("te"));

    board.post(2, 0, Direction::Vertical,"h");
    CHECK(board.read(0,0, Direction::Vertical, 3) == string("teh"));

    board.post(3, 0, Direction::Vertical,"i");
    CHECK(board.read(0,0, Direction::Vertical, 4) == string("tehi"));

    board.post(4, 0, Direction::Vertical,"l");
    CHECK(board.read(0,0, Direction::Vertical, 5) == string("tehil"));

    board.post(5, 0, Direction::Vertical,"a");
    CHECK(board.read(0,0, Direction::Vertical, 6) == string("tehila"));
}
