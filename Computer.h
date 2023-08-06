#ifndef COMPUTER
#define COMPUTER

#include "Player.h"
#include "Move.h"
class Computer: public Player{
    public:
        Computer();
        Move* makeMove();
        std::string getName();
};


#endif