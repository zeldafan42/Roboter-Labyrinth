
CC=g++
CFLAGS=-std=c++11 -Wall -O

all: labrob

labrob: main.o Linksdreher.o BreadthFirstSearch.o DeadEndFiller.o Maze.o Robot.o
	${CC} ${CFLAGS} -o labrob main.o Linksdreher.o BreadthFirstSearch.o DeadEndFiller.o Maze.o Robot.o -pthread

main.o: main.cpp Maze.hpp Robot.hpp Linksdreher.hpp 
	${CC} ${CFLAGS} -c -o main.o main.cpp -pthread

Linksdreher.o: Linksdreher.cpp Linksdreher.hpp Robot.hpp Maze.hpp
	${CC} ${CFLAGS} -c -o Linksdreher.o Linksdreher.cpp

BreadthFirstSearch.o: BreadthFirstSearch.cpp BreadthFirstSearch.hpp Robot.hpp Maze.hpp
	${CC} ${CFLAGS} -c -o BreadthFirstSearch.o BreadthFirstSearch.cpp
	
DeadEndFiller.o: DeadEndFiller.cpp DeadEndFiller.hpp Robot.hpp Maze.hpp
	${CC} ${CFLAGS} -c -o DeadEndFiller.o DeadEndFiller.cpp

Robot.o: Robot.cpp Robot.hpp Maze.hpp
	${CC} ${CFLAGS} -c -o Robot.o Robot.cpp

Maze.o: Maze.cpp Maze.hpp
	${CC} ${CFLAGS} -c -o Maze.o Maze.cpp

clean:
	rm -f labrob main.o Linksdreher.o BreadthFirstSearch.o DeadEndFiller.o Maze.o Robot.o