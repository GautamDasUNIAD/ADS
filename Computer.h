#ifndef COMPUTER
#define COMPUTER

#include "Player.h"
class Computer: public Player{
    public:
        Computer();
        char makeMove();
        std::string getName();
};


#endif
