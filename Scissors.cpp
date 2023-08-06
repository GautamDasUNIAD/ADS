#include "Scissors.h"
#include <string>
#include <vector>


Scissors::Scissors(){
    loses_to.push_back("Rock");
}

std::vector<std::string> Scissors::getLosesTo(){
    return loses_to;
}

std::string Scissors::getName(){
    return move_name;
}
