#include "Monkey.h"
#include <string>
#include <vector>


Monkey::Monkey(){
    loses_to.push_back("Pirate");
    loses_to.push_back("Zombie");
}

std::vector<std::string> Monkey::getLosesTo(){
    return loses_to;
}
std::string Monkey::getName(){
    return move_name;
}

