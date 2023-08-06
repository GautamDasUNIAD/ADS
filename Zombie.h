#ifndef ZOMBIE
#define ZOMBIE

#include <string>
#include <vector>
#include "Move.h"

class Zombie : public Move{
    private:
        //name of the move, e.g: Zombie, Paper, Monkey etc
        std::string move_name = "Zombie";

    public:
        Zombie();
        std::string getName();
        std::vector<std::string> getLosesTo();
};


#endif

