# Program Name: Group Project 1 - Predator Prey Game
# File: 	makefile
# Author: 	Kuljot Biring, Rachel Schlick, Ryan Gross, Sandro Aguilar, Jeesoo Ryoo
# Date: 	February 2019
# Description:	Makefile for Group Project

# Variables to control Makefile operation

# compiler
CXX = g++

# compiler flags
CXXFLAGS = -Wall
CXXFLAGS += -g
CXXFLAGS += -std=c++0x
CXXFLAGS += -pedantic-errors

# source files
CPPs = main.cpp
CPPs += Ant.cpp
CPPs += Game.cpp
CPPs += Menu.cpp
CPPs += Critter.cpp
CPPs += Doodlebug.cpp
CPPs += Ant.cpp
CPPs += utils.cpp

# header files
HPPs = Ant.hpp
HPPs += Game.hpp
HPPs += Menu.hpp
HPPs += Critter.hpp
HPPs += Doodlebug.hpp
HPPs += Ant.hpp
HPPs += utils.hpp

# pre-processed header files
HPPGCHs = Ant.hpp
HPPGCHs += Game.hpp
HPPGCHs += Menu.hpp
HPPGCHs += Critter.hpp
HPPGCHs += Doodlebug.hpp
HPPGCHs += Ant.hpp
HPPGCHs += utils.hpp

# rule to construct names of .o files from .cpp files
OBJECTS = $(CPPS:.cpp=.o)

# executable file 
EXE = predator-prey

# Targets needed to bring the executable up to date
predator-prey: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(EXE) $(OBJECTS)

main.o: main.cpp $(HPPs)
	$(CXX) $(CXXFLAGS) -c main.cpp

Ant.o: Ant.cpp Ant.hpp Critter.cpp Critter.hpp
	$(CXX) $(CXXFLAGS) Ant.cpp

Game.o: Game.cpp Game.hpp
	$(CXX) $(CXXFLAGS) Game.cpp

Menu.o: Menu.cpp Menu.hpp
	$(CXX) $(CXXFLAGS) Menu.cpp

Critter: Critter.cpp Critter.hpp 
	$(CXX) $(CXXFLAGS) Critter.cpp

Doodlebug.o: Doodlebug.cpp Doodlebug.hpp Critter.cpp Critter.hpp
	$(CXX) $(CXXFLAGS) Doodlebug.hpp

Utils.o: utils.cpp utils.hpp
	$(CXX) $(CXXFLAGS) utils.cpp


# Clean-up operations
.PHONY : clean
clean:
	rm -rf $(EXE) $(CPPs) $(OBJECTS) $(GCCHEADERS)

.PHONY : debug
debug:
	valgrind -v --leak-check=full --show-leak-kinds=all --track-origins=yes ./predator-prey
.PHONY : zip
zip:
	zip -D GroupProject_NAMES_HERE.zip $(CPPs) $(HPPs) $(TXTS) makefile *.txt *.pdf
