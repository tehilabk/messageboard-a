#pragma once
#include "Direction.hpp"
#include <string>


namespace ariel{
    class Board;
}


class ariel::Board {
   

   
       
    public: Board();

    public: void Board::post(u_int row, u_int column, Direction direction, string msg);

    public: string Board::read(u_int row, u_int column, Direction direction, u_int length);

    public: void show();
};

