#include "Player.h"
#include "Card.h"
#include <iostream>

Card Player::cardToRemove = Card();

bool Player::play(const Card& card){

std::cout<<"Current: "<<card<<"\n";

std::cout<<this->playerName<<", your turn-\n";

std::cout<<"Your cards: ";

for(int i=0; i<numOfCards; i++)
     std::cout<<"("<<(i+1)<<")"<<cardsList.at(i)<<" ";

int choise;

std::cin>>choise;

while(choise<=0||choise>numOfCards||!card.is_legal (cardsList.at(choise-1))){

if(choise<=0||choise>numOfCards){

    cardsList.push_back(Card::generate_card());
    numOfCards++;
    return false;
}

else {
    std::cout<<"You can't put "<<cardsList.at(choise-1)<<" on "<< card<<"\n";
    std::cin>>choise;
     }

}

cardToRemove=cardsList.at(choise-1);


cardsList.erase((cardsList.begin()+choise-1));
numOfCards--;
return true;

}


