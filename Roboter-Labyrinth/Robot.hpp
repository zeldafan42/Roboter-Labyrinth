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
	Robot(const Maze& maze, const std::string& name);
	virtual void findSolution() = 0;
	void printMaze();
	virtual ~Robot();
	void printSteps();
	virtual void printResult() = 0;
	int countDigits(int number);

protected:
	std::pair<int,int> pos;
	Maze * maze;
	int dir;
	int steps;
	const std::string name;
};

#endif /* ROBOT_HPP_ */
