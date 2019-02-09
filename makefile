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
CXXFLAGS += -c
CXXFLAGS += -std=c++0x
CXXFLAGS += -pedantic-errors

# source files
CPPs = main.cpp
CPPs += Critter.cpp
CPPs += Ant.cpp
CPPs += Doodlebug.cpp
CPPs += Menu.cpp
CPPs += Game.cpp
CPPs += utils.cpp

# header files
HPPs = Ant.hpp
HPPs += Game.hpp
HPPs += Menu.hpp
HPPs += Critter.hpp
HPPs += Doodlebug.hpp
HPPs += utils.hpp

# rule to construct names of .hpp.gch files from .hpp files
# Note: .hpp.gch are the preprocessed header files
HPPGCHs = $(HPPs:.hpp=.hpp.gch)

# rule to construct names of .o files from .cpp files
OBJECTS = $(CPPs:.cpp=.o)

# executable file 
EXE = predator-prey

# Targets needed to bring the executable up to date
predator-prey : $(OBJECTS)
	$(CXX) -o $(EXE) $(OBJECTS)

main.o : main.cpp $(HPPs) $(CPPs)
	$(CXX) $(CXXFLAGS) main.cpp

Critter.o : Critter.cpp Critter.hpp 
	$(CXX) $(CXXFLAGS) Critter.cpp

Ant.o : Ant.cpp Ant.hpp Critter.cpp Critter.hpp
	$(CXX) $(CXXFLAGS) Ant.cpp

Game.o : $(HPPs) $(CPPs)
	$(CXX) $(CXXFLAGS) $(CPPs)

Menu.o : Menu.cpp Menu.hpp
	$(CXX) $(CXXFLAGS) Menu.cpp

Doodlebug.o : Doodlebug.cpp Doodlebug.hpp Critter.cpp Critter.hpp
	$(CXX) $(CXXFLAGS) Doodlebug.hpp

Utils.o : utils.cpp utils.hpp
	$(CXX) $(CXXFLAGS) utils.cpp


# Clean-up operations
.PHONY : clean
clean:
	rm -rf $(EXE) $(OBJECTS) $(HPPGCHs)
.PHONY : debug
debug:
	valgrind -v --leak-check=full --show-leak-kinds=all --track-origins=yes ./predator-prey
.PHONY : zip
zip:
	zip -D GroupProject_NAMES_HERE.zip $(CPPs) $(HPPs) $(TXTS) makefile *.txt *.pdf
.PHONY : run
run:
	./predator-prey
