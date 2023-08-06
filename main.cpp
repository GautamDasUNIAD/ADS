#include <string>
#include "Player.h"
#include "Human.h"
#include "Computer.h"
#include "Referee.h"
#include "Move.h"

#include "MoveFactory.h"
#include <iostream>
#include <map>

int main(void){
    human h("Human 1");
    // std::cout << h.getName();
    // char move = h.makeMove();
    // std::cout << move;

    human pc("Human 2");

    // move = pc.makeMove();
    // std::cout << move;
    // std::cout << pc.getName() << "\n calling ref function";
    
    Referee ref;
    Player* humanptr = &h;
    Player* compptr = &pc;
    Player* winnerptr = ref.refGame(humanptr, compptr);
    if (winnerptr == nullptr){
        std::cout << "It's a Tie";
    }
    else {
        std::cout << winnerptr->getName() << " Wins";
    }
    return 0;
}