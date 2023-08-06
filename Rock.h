#ifndef ROCK
#define ROCK

#include <string>
#include <vector>
#include "Move.h"

class Rock : public Move{
    private:
        //name of the move, e.g: Rock, Paper, Monkey etc
        std::string move_name = "Rock";

    public:
        Rock();
        std::string getName();
        std::vector<std::string> getLosesTo();
};


#endif

