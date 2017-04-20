#This is a Makefile for Assignment5
FLAGS = -Wall -g
CC = g++

all:	TwoPipesTwoChildren TwoPipesThreeChildren dynpipe clean

TwoPipesTwoChildren:	TwoPipesTwoChildren.o
	$(CC) -o TwoPipesTwoChildren TwoPipesTwoChildren.o
TwoPipesThreeChildren:	TwoPipesThreeChildren.o
	$(CC) -o TwoPipesThreeChildren TwoPipesThreeChildren.o
dynpipe:	DynPipe.o
	$(CC) -o dynpipe DynPipe.o
TwoPipesTwoChildren.o:	
	$(CC) $(FLAGS) -c TwoPipesTwoChildren.cpp
TwoPipesThreeChildren.o:
	$(CC) $(FLAGS) -c TwoPipesThreeChildren.cpp
DynPipe.o:
	$(CC) $(FLAGS) -c DynPipe.cpp
clean:	
	rm -f TwoPipesTwoChildren.o TwoPipesThreeChildren.o DynPipe.o

