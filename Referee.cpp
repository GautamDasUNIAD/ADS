#include "Referee.h"
#include "Player.h"

#include <vector>
#include <string>

Referee::Referee(){}

Player * Referee::refGame(Player * player1, Player * player2){
    //In order to add more move, no changes are required here
    //Just have to create a new class that inherits from the move class
    //And add the new class to the map in movefactor.cpp
    //Hence, OPEN-CLOSED Principle is not violated
    
    Move* p1move = player1->makeMove();
    Move* p2move = player2->makeMove();

    
    
    //check if p1move is among the move that p2move loses to:
    
    //Step 1: Get the vector that contains the moves p2move loses to
    std::vector<std::string> p2LosesTo;
    p2LosesTo = p2move->getLosesTo();


    //Step 2: Loop through the vector to see if p1move is in there
    int vecSize = p2LosesTo.size();
    for(int i = 0; i < vecSize; i++)
    {
        if (p2LosesTo[i] == p1move->getName()){
            //if p1move is in this list, then return pointer to player1
            return player1;
        }
    }
    
    //if player1 did not win then it is either a draw or p2win,

    //check for draw
    if (p2move->getName() == p1move->getName()){
        
        return nullptr;
    }
    //Only other option, p2 wins

    else {
        return player2;
    }

    //^^ Becase of that if either of the two moves is incompatible or invalid, player2 is return and shown as the victor
}
