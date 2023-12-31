all: main

main: main.o
	g++ -o main main.o -I/opt/homebrew/Cellar/sfml/2.6.1/include/ -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -c main.cpp -o main.o -I/opt/homebrew/Cellar/sfml/2.6.1/include/