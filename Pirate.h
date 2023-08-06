#ifndef PIRATE
#define PIRATE

#include <string>
#include <vector>
#include "Move.h"

class Pirate : public Move{
    private:
        //name of the move, e.g: Pirate, Paper, Monkey etc
        std::string move_name = "Pirate";

    public:
        Pirate();
        std::string getName();
        std::vector<std::string> getLosesTo();
};


#endif

