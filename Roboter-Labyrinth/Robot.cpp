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

int Robot::countDigits(int number)
{
	int i = 0;
	int product = 1;

	for(i=0;i<10;i++)
	{
		if(number < product)
		{
			return i;
		}
		product *= 10;
	}

	return -1;
}

void Robot::printMaze()
{
	maze->printMaze();
}
