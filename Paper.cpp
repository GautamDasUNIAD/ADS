#include "Paper.h"
#include <string>
#include <vector>


Paper::Paper(){
    loses_to.push_back("Scissors");
}

std::vector<std::string> Paper::getLosesTo(){
    return loses_to;
}
std::string Paper::getName(){
    return move_name;
}

