#ifndef SCISSORS
#define SCISSORS

#include <string>
#include <vector>
#include "Move.h"

class Scissors : public Move{
    private:
        //name of the move, e.g: Scissors, Paper, Monkey etc
        std::string move_name = "Scissors";

    public:
        Scissors();
        std::string getName();
        std::vector<std::string> getLosesTo();
};


#endif

