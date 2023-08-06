
#ifndef HUMAN
#define HUMAN

#include <string>
#include "Player.h"
#include "Move.h"

class human: public Player{
    public:
        human();
        human(std::string n);
        Move* makeMove();
        std::string getName();
};

#endif