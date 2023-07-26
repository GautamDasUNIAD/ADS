#ifndef COMPUTER
#define COMPUTER

#include "player.h"
class Computer: public Player{
    public:
        Computer();
        char makeMove();
        std::string getName();
};


#endif