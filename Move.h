#ifndef MOVE
#define MOVE

#include <string>
#include <vector>

class Move{
    protected:
        //name of the move, e.g: Rock, Paper, Monkey etc
        std::string move_name;
        
        //Vector of the moves it will lose to. For example, if the move is Monkey, then this vector will have "Pirate" and "Zombie"
        std::vector<std::string> loses_to;
        
    public: 
        //Returns the name of the move
        virtual std::string getName() = 0;

        //Returns  the vector that contains the moves it can lose to.
        virtual std::vector<std::string> getLosesTo() = 0;
};


#endif

