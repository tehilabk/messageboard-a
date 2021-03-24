
#include "doctest.h"
#include "Board.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;


//Good cases

TEST_CASE("read empty bord")
{
    Board board;
    CHECK(board.read(0,0, Direction::Horizontal, 5) == "_____");
}

//post and then read(not empty)
//change the bord and read the changes

//Bad cases

//read mor than length
//read in place bigger than size 
//