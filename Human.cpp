#include "Human.h"
#include <string>
#include <iostream>

Human::Human(){
    name = "Human";
};

Human::Human(std::string n){
    name = n;
};

char Human::makeMove(){
    // get input
    char move;
    std::cout << "Enter move: ";
    std::cin >> move;

    // return input
    return move;
}

std::string Human::getName(){
    return name;
}
