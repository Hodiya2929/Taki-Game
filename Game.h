#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Card.h"

enum class Turn { FORWARD, BACKWARD };

class Game {

private:
	
int numOfPlayers;	
int numOfCards;
int currentPlayer; 
std::vector<Player> playersList;
Turn turn;
Card currentCard;

//Avoiding the default copy constructor and operator =  
Game(const Game& otherGame){};

Game& operator = (const Game& otherGame){

    Game game;
    return *this;
};

public:

Game(){
numOfPlayers=0; numOfCards=0;    currentPlayer=0;   turn=Turn::FORWARD;    currentCard=Card::generate_card();
}

//No need to have getters, since mani function uses only the start method

void start();
	
};
#endif




