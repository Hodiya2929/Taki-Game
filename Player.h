#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include <string>
#include <vector>

class Player {

private:

	int numOfCards;
	std:: string playerName;
	std:: vector<Card> cardsList;

public:

//access to private fields of Player class
friend class Game;

//save the last card that was removed in order 
static Card cardToRemove;

//copy constructor
Player (const Player& other) : numOfCards{other.numOfCards}, playerName{other.playerName} {
for(int i=0; i<other.cardsList.size();i++){

		Card temp=other.cardsList[i];
		cardsList.push_back(temp);
	}
}

// = operator
Player& operator=(const Player& other) {
	
	numOfCards=other.numOfCards;
	playerName=other.playerName;
	
cardsList.reserve(other.cardsList.size());

	for(int i=0; i<other.cardsList.size();i++){

	Card card=other.cardsList[i];
	cardsList.push_back(card);
	}

	return *this;
	}; 

//default construtor and init list constructor
Player(int num=0, std::string name="" ): numOfCards{num}, playerName{name}{};

//getters
int get_numOfCards() const { return numOfCards; }
std:: string get_playerName() const { return playerName;}
std:: vector<Card> get_cardsList() const {return cardsList;}

//play the player turn
bool play (const Card& currentCard);   

};

#endif



