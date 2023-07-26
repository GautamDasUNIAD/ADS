#include "Referee.h"
#include "Player.h"
#include <iostream>

Referee::Referee(){}

Player * Referee::refGame(Player * player1, Player * player2){
    char p1move = player1->makeMove();
    char p2move = player2->makeMove();

    // std::cout << p1move << p2move;
    
    if (p2move == 'R'){
        if (p1move == 'P'){
            return player1;
        } else if (p1move == 'R'){
            return nullptr;
        } else {
            return player2;
        }
    } else if (p2move == 'P'){
        if (p1move == 'P'){
            return nullptr;
        } else if (p1move == 'R'){
            return player2;
        } else {
            return player1;
        }
    } else {
        if (p1move == 'P'){
            return player2;
        } else if (p1move == 'R'){
            return player1;
        } else {
            return nullptr;
        }
    }
}
