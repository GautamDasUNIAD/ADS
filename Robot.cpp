#include "Robot.h"
#include <string>
#include <vector>


Robot::Robot(){
    loses_to.push_back("Pirate");
    loses_to.push_back("Monkey");
}

std::vector<std::string> Robot::getLosesTo(){
    return loses_to;
}
std::string Robot::getName(){
    return move_name;
}

