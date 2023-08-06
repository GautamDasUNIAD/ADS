#ifndef MONKEY
#define MONKEY

#include <string>
#include <vector>
#include "Move.h"

class Monkey : public Move{
    private:
        //name of the move, e.g: Monkey, Paper, Monkey etc
        std::string move_name = "Monkey";

    public:
        Monkey();
        std::string getName();
        std::vector<std::string> getLosesTo();
};


#endif

