
#ifndef HUMAN
#define HUMAN

#include <string>
#include "Player.h"

class Human: public Player{
    public:
        Human();
        Human(std::string n);
        char makeMove();
        std::string getName();
};

#endif
