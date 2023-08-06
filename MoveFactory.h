#ifndef MOVEFACTORY
#define MOVEFACTORY

#include "Move.h"
#include "Rock.h"
#include "Paper.h"
#include "Scissors.h"
#include "Zombie.h"
#include "Monkey.h"
#include "Pirate.h"
#include "Robot.h"
#include "Ninja.h"
#include <map>
#include <string>


class Movefactory{
        //Learnt about maps from Geeks for Geeks, link: https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/

        //A map of names of moves as keys (strings) and pointers to those objects 
        std::map<std::string, Move*> pointers;
    public:
        Movefactory();
        Move* CreateMoveObject(std::string move_name);


};


#endif