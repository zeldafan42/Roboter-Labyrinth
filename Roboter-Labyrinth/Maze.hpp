/*
 * Maze.hpp
 *
 *  Created on: 23.05.2015
 *      Author: Christine
 */

#ifndef MAZE_HPP_
#define MAZE_HPP_

#include <vector>
#include <utility>
#include <iostream>

class Maze
{
public:
	Maze(const std::string& filename);
	Maze(const Maze& maze);
	~Maze();
	std::pair<int,int> getStart() const;
	std::pair<int,int> getEnd() const;
	bool passable(std::pair<int,int>) const;
	void mark(std::pair<int,int>, char marker);
	void printMaze() const;



private:
	int searchForExits(int x, int y, int xInc, int yInc, int endX, int endY, int count);
	std::vector<std::string > field;
	std::pair<int,int> start;
	std::pair<int,int> end;

};

#endif /* MAZE_HPP_ */
