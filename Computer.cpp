#include "Computer.h"
#include "Move.h"
#include "MoveFactory.h"
#include <string>

Computer::Computer(){
    name = "Computer";
}

std::string Computer::getName(){
    return name;
}

Move* Computer::makeMove(){
    std::string move = "Rock";
    Movefactory Factory;
    return Factory.CreateMoveObject(move);
    // return move;
}