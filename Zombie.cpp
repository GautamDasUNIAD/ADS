#include "Zombie.h"
#include <string>
#include <vector>


Zombie::Zombie(){
    loses_to.push_back("Robot");
    loses_to.push_back("Ninja");
}

std::vector<std::string> Zombie::getLosesTo(){
    return loses_to;
}
std::string Zombie::getName(){
    return move_name;
}

