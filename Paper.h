#ifndef PAPER
#define PAPER

#include <string>
#include <vector>
#include "Move.h"

class Paper : public Move{
    private:
        //name of the move, e.g: Paper, Paper, Monkey etc
        std::string move_name = "Paper";

    public:
        Paper();
        std::string getName();
        std::vector<std::string> getLosesTo();
};


#endif

