#include "Pirate.h"
#include <string>
#include <vector>


Pirate::Pirate(){
    loses_to.push_back("Zombie");
    loses_to.push_back("Ninja");
}

std::vector<std::string> Pirate::getLosesTo(){
    return loses_to;
}
std::string Pirate::getName(){
    return move_name;
}

