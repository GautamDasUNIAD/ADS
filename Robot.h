#ifndef ROBOT
#define ROBOT

#include <string>
#include <vector>
#include "Move.h"

class Robot : public Move{
    private:
        //name of the move, e.g: Robot, Paper, Monkey etc
        std::string move_name = "Robot";

    public:
        Robot();
        std::string getName();
        std::vector<std::string> getLosesTo();
};


#endif

