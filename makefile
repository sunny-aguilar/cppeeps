# Program Name: Group Project 1 - Predator Prey Game
# Author: 	Kuljot Biring, Rachel Schlick, Ryan Gross, Sandro Aguilar, Jeesoo Ryoo
# Date: 	February 17, 2019
# Description:	Makefile for Group Project

CXX = g++
CXXFLAGS = -Wall
CXXFLAGS += -g
CXXFLAGS += -c
CXXFLAGS += -std=c++0x
CXXFLAGS += -pedantic-errors
CPPs = main.cpp
CPPs += Critter.cpp
CPPs += Ant.cpp
CPPs += Doodlebug.cpp
CPPs += Menu.cpp
CPPs += Game.cpp
CPPs += utils.cpp
HPPs = Ant.hpp
HPPs += Game.hpp
HPPs += Menu.hpp
HPPs += Critter.hpp
HPPs += Doodlebug.hpp
HPPs += utils.hpp

# Note: .hpp.gch are the preprocessed header files
HPPGCHs = $(HPPs:.hpp=.hpp.gch)
OBJECTS = $(CPPs:.cpp=.o)
EXE = predator-prey

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

.PHONY : clean
clean:
	rm -rf $(EXE) $(OBJECTS) $(HPPGCHs)
.PHONY : debug
debug:
	valgrind -v --leak-check=full --show-leak-kinds=all --track-origins=yes ./predator-prey
.PHONY : zip
zip:
	zip -D GroupProject_Group20.zip $(CPPs) $(HPPs) $(TXTS) makefile *.txt *.pdf
.PHONY : run
run:
	./predator-prey
