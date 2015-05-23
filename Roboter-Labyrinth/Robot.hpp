/*
 * Robot.hpp
 *
 *  Created on: 23.05.2015
 *      Author: Christine
 */

#ifndef ROBOT_HPP_
#define ROBOT_HPP_

class Maze;

#include <utility>

class Robot {
public:
	Robot(Maze maze);
	virtual Maze& solve() = 0;
	virtual ~Robot();

private:
	std::pair<int,int> pos;
};

#endif /* ROBOT_HPP_ */
