TextAdventure: init.o game.o main.c
	g++ -Wall -c++11 -o TextAdventure -g main.c -I~Library/Frameworks/SDL2.framework/Headers -framework SDL2 init.o game.o 
init.o: init.h init.c
	g++ -Wall -c++11 -g -o init.o -c init.c	
game.o: game.h location.h item.h player.h  game.c
	g++ -Wall -c++11 -g -o game.o -c game.c   