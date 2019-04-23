#!make -f

# variables contains the compile commands
CXX = clang++-5.0
CXXFLAGS = -std=c++11

# 4 o files needs to be linked in order to create a.out executable file 
a.out: main.o Player.o Card.o Game.o
	$(CXX) $(CXXFLAGS) $^ -o a.out

#Rule for creating main.o the dependecies fron dependecies chart 
main.o: main.cpp Game.h
	$(CXX) $(CXXFLAGS) --compile main.cpp  

#Make is "smart" - no neet to note the Game.cpp and the command
Game.o: Player.h Card.h

Player.o: Player.h Card.h 

Card.o: Card.h

clean:
	rm -f *.o a.out


