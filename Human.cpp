#include "Human.h"
#include "MoveFactory.h"
#include <string>
#include <iostream>

human::human(){
    name = "Human";
};

human::human(std::string n){
    name = n;
};

Move* human::makeMove(){
    // get input
    std::string move;
    std::cout << "Enter move: ";
    std::cin >> move;

    Movefactory Factory;
    return Factory.CreateMoveObject(move);
}

std::string human::getName(){
    return name;
}
