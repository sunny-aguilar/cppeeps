CC=g++
SRCS = main.cpp Ant.cpp Doodlebug.cpp

all: ${SRCS}
	${CC} ${SRCS} -std=c++11 -o predator-prey
clean:
	rm predator-prey