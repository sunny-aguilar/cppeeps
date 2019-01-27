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
OBJECTS += Ant.o
OBJECTS += Doodlebug.o

HPPs = Ant.hpp
HPPs += Doodlebug.hpp

CPPs = main.cpp
CPPs += Ant.cpp
CPPs += Doodlebug.cpp


# Targets needed to bring the executable up to date
predator-prey: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o predator-prey $(OBJECTS)

main.o: main.cpp $(HPPs)
	$(CXX) $(CXXFLAGS) -c main.cpp

Ant.o: Ant.hpp

Doodlebug.o: Doodlebug.hpp


# Clean-up operations
clean:
	rm predator-prey

debug:
	valgrind -v --leak-check=full --show-leak-kinds=all --track-origins=yes ./predator-prey

zip:
	zip -D GroupProject_NAMES_HERE.zip $(CPPs) $(HPPs) $(TXTS) makefile *.txt *.pdf