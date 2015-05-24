/*
 * Robot.cpp
 *
 *  Created on: 23.05.2015
 *      Author: Christine
 */

#include "Robot.hpp"



Robot::Robot(const Maze& maze, const std::string& name) : name(name)
{
	this->maze = new Maze(maze);
	dir = 0;
	steps = 0;
	std::cout << "Starting " << name << std::endl;
}

Robot::~Robot()
{
	delete maze;
}

void Robot::printSteps()
{
	std::cout << "Robot " << name << " needed " << steps << " steps to get through the maze" << std::endl;
}
