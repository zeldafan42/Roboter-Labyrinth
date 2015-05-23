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
	virtual ~Maze();
	std::pair<int,int> getStart();
	std::pair<int,int> getEnd();
	bool passable(std::pair<int,int>);
	bool mark(std::pair<int,int>, char marker);


private:
	std::vector<std::string > field;

};

#endif /* MAZE_HPP_ */
