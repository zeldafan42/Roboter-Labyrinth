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
	this->pos = maze->getStart();

	while(pos != maze->getEnd())
	{
		turnAndMove();
	}

	maze->printMaze();
}


void Linksdreher::turnAndMove()
{
	bool leftFree = false;
	std::pair<int,int> targetPosition = pos;



	switch(this->dir)
	{
		case 0: 	targetPosition.first--;
					break;

		case 1:		targetPosition.second--;
					break;

		case 2:		targetPosition.first++;
					break;

		case 3:		targetPosition.second++;
					break;

		default:	break;

	}

	leftFree = maze->passable(targetPosition);

	if(leftFree)
	{
		this->dir = (this->dir+3) %4; // turns left
		move(targetPosition);
		return;
	}
	else
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
		if(maze->passable(targetPosition)) // Now looks in front of him
		{
			move(targetPosition);
			return; //keeps his facing direction
		}
		else
		{
			targetPosition = pos;
			switch(this->dir)
			{
				case 0:		targetPosition.first++;
							break;

				case 1:		targetPosition.second++;
							break;

				case 2: 	targetPosition.first--;
							break;

				case 3:		targetPosition.second--;
							break;

				default:	break;

			}

			if(maze->passable(targetPosition)) // Now looks to the right
			{
				this->dir = (this->dir+1) %4; // turns right
				move(targetPosition);
				return;
			}
			else
			{
				this->dir = (this->dir+2) %4; //makes an U-turn
				move(targetPosition);
				return;
			}
		}
	}


}

void Linksdreher::move(std::pair<int,int> targetPosition)
{
	maze->mark(this->pos,'L');
	this->pos = targetPosition;
	maze->mark(this->pos,'X');
}





















