
#ifndef HUMAN
#define HUMAN

#include <string>
#include "Player.h"
#include "Move.h"

class Human: public Player{
    public:
        Human();
        Human(std::string n);
        Move* makeMove();
        std::string getName();
};

#endif