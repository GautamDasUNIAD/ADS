#include "Human.h"
#include "MoveFactory.h"
#include <string>
#include <iostream>

Human::Human(){
    name = "Human";
};

Human::Human(std::string n){
    name = n;
};

Move* Human::makeMove(){
    // get input
    std::string move;
    std::cout << "Enter move: ";
    std::cin >> move;

    Movefactory Factory;
    return Factory.CreateMoveObject(move);
}

std::string Human::getName(){
    return name;
}
