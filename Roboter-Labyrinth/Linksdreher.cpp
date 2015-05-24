/*
 * Linksdreher.cpp
 *
 *  Created on: 23.05.2015
 *      Author: Zombieranke
 */

#include "Linksdreher.hpp"
#include <utility>

Linksdreher::Linksdreher(const Maze& maze) : Robot(maze)
{
	// TODO Auto-generated constructor stub

}

Linksdreher::~Linksdreher()
{
	// TODO Auto-generated destructor stub
}

void Linksdreher::printSolution()
{
	steps = 0;
	this->pos = maze->getStart();

	while(pos != maze->getEnd())
	{
		steps += turnAndMove();
	}

	maze->printMaze();
}

void Linksdreher::printSteps()
{
	std::cout << "Robot 1 \"Linksdreher\" needed" << steps << " steps to get through the maze" << std::endl;
}


bool Linksdreher::turnAndMove()
{
	int i = 0;
	std::pair<int,int> targetPosition = pos;

	this->dir = (this->dir+3) %4;


	for(i = 0; i < 3; i++)
	{
		targetPosition = pos;
		switch(this->dir)
		{
			case 0:		targetPosition.second--;
						break;

			case 1:		targetPosition.first++;
						break;

			case 2:		targetPosition.second++;
						break;

			case 3: 	targetPosition.first--;
						break;

			default:	break;

		}
		if(maze->passable(targetPosition))
		{
			move(targetPosition);
			return true;
		}
		else
		{
			this->dir = (this->dir+1) %4;
			return false;
		}
	}
	return false;
}

void Linksdreher::move(std::pair<int,int> targetPosition)
{
	maze->mark(this->pos,'L');
	this->pos = targetPosition;
	maze->mark(this->pos,'X');
}





















