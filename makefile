# File: 	makefile
# Author: 	Kuljot Biring, Rachel Schlick, Ryan Gross, Sandro Aguilar, Jeesoo Ryoo
# Date: 	February 2019
# Description:	Makefile for Group Project

# Variables to control Makefile operation
CXX = g++

CXXFLAGS = -Wall
CXXFLAGS += -g
CXXFLAGS += -std=c++0x

OBJECTS = main.o
OBJECTS += Game.o
OBJECTS += Menu.o
OBJECTS += Critter.o
OBJECTS += Doodlebug.o
OBJECTS += Ant.o
OBJECTS += utils.o

HPPs = Ant.hpp
HPPs += Game.hpp
HPPs += Menu.hpp
HPPs += Critter.hpp
HPPs += Doodlebug.hpp
HPPs += Ant.hpp
HPPs += utils.hpp

CPPs = main.cpp
CPPs += Ant.cpp
CPPs += Game.cpp
CPPs += Menu.cpp
CPPs += Critter.cpp
CPPs += Doodlebug.cpp
CPPs += Ant.cpp
CPPs += utils.cpp

# Targets needed to bring the executable up to date
predator-prey: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o predator-prey $(OBJECTS)

main.o: main.cpp $(HPPs)
	$(CXX) $(CXXFLAGS) -c main.cpp

Ant.o: Ant.hpp

Game.o: Game.cpp

Menu.o: Menu.cpp

Critter: Critter.cpp

Doodlebug.o: Doodlebug.hpp

Ant.o: Ant.cpp

Utils.o: utils.cpp


# Clean-up operations
clean:
	rm predator-prey

debug:
	valgrind -v --leak-check=full --show-leak-kinds=all --track-origins=yes ./predator-prey

zip:
	zip -D GroupProject_NAMES_HERE.zip $(CPPs) $(HPPs) $(TXTS) makefile *.txt *.pdf