
#ifndef HUMAN
#define HUMAN

#include <string>
#include "Player.h"

class human: public Player{
    public:
        human();
        human(std::string n);
        char makeMove();
        std::string getName();
};

#endif