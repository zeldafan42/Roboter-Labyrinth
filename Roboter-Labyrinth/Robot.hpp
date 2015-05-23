/*
 * Robot.hpp
 *
 *  Created on: 23.05.2015
 *      Author: Christine
 */

#ifndef ROBOT_HPP_
#define ROBOT_HPP_

#include "Maze.hpp"
#include <utility>

class Robot {
public:
	Robot(const Maze& maze);
	virtual void printSolution() = 0;
	virtual ~Robot();

protected:
	std::pair<int,int> pos;
	Maze * maze;
	int dir;
};

#endif /* ROBOT_HPP_ */
