#ifndef NINJA
#define NINJA

#include <string>
#include <vector>
#include "Move.h"

class Ninja : public Move{
    private:
        //name of the move, e.g: Ninja, Paper, Monkey etc
        std::string move_name = "Ninja";

    public:
        Ninja();
        std::string getName();
        std::vector<std::string> getLosesTo();
};


#endif

