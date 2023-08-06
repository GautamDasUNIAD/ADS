#include "Ninja.h"
#include <string>
#include <vector>


Ninja::Ninja(){
    loses_to.push_back("Monkey");
    loses_to.push_back("Robot");
}

std::vector<std::string> Ninja::getLosesTo(){
    return loses_to;
}
std::string Ninja::getName(){
    return move_name;
}

