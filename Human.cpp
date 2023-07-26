#include "Human.h"
#include <string>
#include <iostream>

human::human(){
    name = "Human";
};

human::human(std::string n){
    name = n;
};

char human::makeMove(){
    // get input
    char move;
    std::cout << "Enter move: ";
    std::cin >> move;

    // return input
    return move;
}

std::string human::getName(){
    return name;
}
