#include <string>
#include "Player.h"
#include "Human.h"
#include "Computer.h"
#include "Referee.h"
#include <iostream>

int main(void){
    human h("human12");
    // std::cout << h.getName();
    // char move = h.makeMove();
    // std::cout << move;

    Computer pc;

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