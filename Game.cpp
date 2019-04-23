#include "Game.h"
#include "Card.h"
#include "Player.h"
#include "string.h"


void Game::start(){

std::cout<<"How many players?\n";

std::cin>>numOfPlayers; 

if(!std::cin || numOfPlayers<=0){

std::cout<<"Invalid input, can't load game\n";
return;

}

std::cout<<"How many cards?\n";

std::cin>>numOfCards;

if(!std::cin || numOfCards<=0){

std::cout<<"Invalid input, can't load game\n";
return;

}

std::string tempName;

playersList.reserve(numOfPlayers); //avoid the automatic reallocation

for(int i=0; i<numOfPlayers; i++){

std::cout<< "player number "<< (i+1) <<" name: ";

std::cin>>tempName;

playersList.push_back(Player(numOfCards, tempName));


 playersList[i].cardsList.reserve(numOfCards); //avoid the automatic reallocation

    for(int j=0; j<numOfCards; j++)
       playersList[i].cardsList.push_back(Card::generate_card());

std::cout<< std::endl; 
}

bool played;

while (true){
std::cout<<"\n"<<"turn of: "<<currentPlayer+1<<"\n";
played=playersList.at(currentPlayer).play(currentCard);


    if(played){//last player had a legal card

                if(playersList.at(currentPlayer).get_numOfCards()==0){
                        std::cout<<playersList.at(currentPlayer).get_playerName()<<" wins!\n";
                        return;
                                 }

//change the current card to be the last played card
currentCard = Player::cardToRemove;

if(currentCard.get_sign()==sign::STOP){
    if(turn==Turn::FORWARD)
        currentPlayer=(currentPlayer+2)%numOfPlayers;
    else currentPlayer=(currentPlayer+numOfPlayers-2)%numOfPlayers;  
}

else if(currentCard.get_sign()==sign::PLUS){}

else if(currentCard.get_sign()==sign::CD){

    if(turn==Turn::FORWARD){
        turn=Turn::BACKWARD;
        currentPlayer=(currentPlayer+numOfPlayers-1) % numOfPlayers;
    }
    else{
        turn=Turn::FORWARD;
        currentPlayer=(currentPlayer+1) % numOfPlayers;
    }
    } 
else {

    if(turn==Turn::FORWARD)
            currentPlayer=(currentPlayer+1) % numOfPlayers;
    else currentPlayer=(currentPlayer+numOfPlayers-1) % numOfPlayers;
}

}
//last player doesnt have a legal card and returned false
    else{
         if(turn==Turn::FORWARD)
            currentPlayer=(currentPlayer+1) % numOfPlayers;
        else currentPlayer=(currentPlayer+numOfPlayers-1) % numOfPlayers;
    }
}

}




