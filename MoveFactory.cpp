#include "MoveFactory.h"
#include "Move.h"

Movefactory::Movefactory(){
    pointers["Rock"] = new Rock;
    pointers["Paper"] = new Paper;
    pointers["Scissors"] = new Scissors;
    pointers["Zombie"] = new Zombie;
    pointers["Monkey"] = new Monkey;
    pointers["Pirate"] = new Pirate;
    pointers["Robot"] = new Robot;
    pointers["Ninja"] = new Ninja;
    
}
Move* Movefactory::CreateMoveObject(std::string move_name){
    return pointers[move_name]; 
}