#include "Computer.h"
#include <string>

Computer::Computer(){
    name = "Computer";
}

std::string Computer::getName(){
    return name;
}

char Computer::makeMove(){
    char move = 'R';
    return move;
}