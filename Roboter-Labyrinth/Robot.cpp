/*
 * Robot.cpp
 *
 *  Created on: 23.05.2015
 *      Author: Christine
 */

#include "Robot.hpp"

Robot::Robot(const Maze& maze)
{
	this->maze = new Maze(maze);
	dir = 0;
}

Robot::~Robot()
{
	// TODO Auto-generated destructor stub
}

