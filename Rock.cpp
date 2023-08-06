#include "Rock.h"
#include <string>
#include <vector>


Rock::Rock(){
    loses_to.push_back("Paper");
}

std::vector<std::string> Rock::getLosesTo(){
    return loses_to;
}
std::string Rock::getName(){
    return move_name;
}

