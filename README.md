# Taki-Game

This project is a CPP Taki game.

The project includes:
 3 header files: Card.h, Player.h and Game.h
4.CPP files: Card.cpp, Player.cpp, Game.cpp and main.cpp
A Makefile based on the dependency chart of the program.

Each card is made from a sign and a color. 
The card class contains the following methods:
is_legal - take as input a card and returns true if and only if the argument card is legal, otherwise returns false.
Operator overloading << to overload the card printing
A static function 'generate_card' which returns an arbitrary card once it's called. 

A player is represented by a name, a number of cards and a vector that contains all user's cards in any given moment.
Game class is a friend class of the player class, in order to have access to a player's private fields. 
The player class contains a static field: 'cardToRemove'. This static field remembers the last card that was removed and in that way, the game class can update the current card.
The main method of the Player class is 'play', which returns a boolean variable. The 'play' function presents to the player the current card, his cards and asks him to choose a card from his list. The program takes the user input and gives three options:
1. The user chose an illegal card and thus required to reinput again his choice.
2. The user chose a number that is smaller than 0 or higher than the size of his cards list - the program adds a card to the player's vector and increment the 'numOfCards' variable by 1 and return false.
3. The user did choose a legal option and thus the program removes the card from the player's vector and returns true.

The Game class is represented by the following variables:
1. The number of players.
2. The number of cards.
3.The current turn - represented by an integer number.
4. Vector of players.
5. The direction of the turn - forward or backward.
6. The current card.
The main method of the Game class and actually for the entire program is the 'start' method. The method asks for the number of players and cards and initializes the name and cards for each player, in case of bad input e.g 0 or negative number the program outputs a message and returns.
Next, the game begins:  the program iterates over the player's vector by the order determined by the 'currentPlayer' variable.
The winner is the players with no cards. 
If the player returned false then the 'currentCard' variable doesn't change and the program moves on to the next player depends on the direction, in the 'turn' variable.
In case the 'play' method returned true, then the 'start' method changes the 'currentCard' variable to be the same as 'cardToRemove' variable and update the turn according to the game rules.

The main.cpp instantiating an object of the game class on the stack and start the 'start' method.












