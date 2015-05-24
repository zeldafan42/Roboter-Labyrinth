/*
 * DeadEndFiller.cpp
 *
 *  Created on: 24.05.2015
 *      Author: Zombieranke
 */

#include "DeadEndFiller.hpp"
#include <utility>

DeadEndFiller::DeadEndFiller(const Maze& maze) : Robot(maze) {
	// TODO Auto-generated constructor stub

}

DeadEndFiller::~DeadEndFiller() {
	// TODO Auto-generated destructor stub
}

void DeadEndFiller::printSolution()
{
	while(fillDeadEnds())
	{
		maze->printMaze();
	}
	maze->printMaze();

	this->pos = maze->getStart();

	while(pos != maze->getEnd())
	{
		turnAndMove();
	}

	maze->printMaze();
}


int DeadEndFiller::fillDeadEnds()
{
	int i = 0;
	int j = 0;
	std::pair<int, int> bounds = maze->getBounds();
	int width = bounds.first;
	int height = bounds.second;
	bool didFill = false;



	for(j=0; j<height ; j++)
	{
		for(i=0; i<width ; i++)
		{
			if(getNeighbours(std::make_pair(i,j), width, height) == 3)
			{
				didFill = (recursiveFill(std::make_pair(i,j), width, height) || didFill);
			}
		}
	}


	return didFill;
}

int DeadEndFiller::getNeighbours(std::pair<int,int>currentField, int width, int height)
{
	int wallCount = 0;
	std::pair<int, int> potentialWall = currentField;
	int x = currentField.first;
	int y = currentField.second;


	if((x-1) >= 0)
	{
		potentialWall.first--;
		wallCount += (maze->isMarked(potentialWall, '#') || maze->isMarked(potentialWall, 'D'));
		potentialWall.first++;
	}

	if((y-1) >= 0)
	{
		potentialWall.second--;
		wallCount += (maze->isMarked(potentialWall, '#') || maze->isMarked(potentialWall, 'D'));
		potentialWall.second++;
	}


	if((x+1) < width)
	{
		potentialWall.first++;
		wallCount += (maze->isMarked(potentialWall, '#') || maze->isMarked(potentialWall, 'D'));
		potentialWall.first--;
	}

	if((y+1) < height)
	{
		potentialWall.second++;
		wallCount += (maze->isMarked(potentialWall, '#') || maze->isMarked(potentialWall, 'D'));
		potentialWall.second--;
	}


	return wallCount;
}


bool DeadEndFiller::recursiveFill(std::pair<int,int>currentField, int width, int height)
{
	std::pair<int, int> nextDeadEndField = currentField;
	int x = currentField.first;
	int y = currentField.second;

	if(!maze->isMarked(currentField, '#') && !maze->isMarked(currentField, 'D')) //checks whether the field is not already a wall
	{
		maze->mark(currentField,'D');
	}
	else
	{
		return false;
	}


	if((x-1) >= 0)
	{
		nextDeadEndField.first--;
		if(getNeighbours(nextDeadEndField,width,height) == 3)
		{
			recursiveFill(nextDeadEndField, width, height);
			return true;
		}
		nextDeadEndField.first++;
	}


	if((y-1) >= 0)
	{
		nextDeadEndField.second--;
		if(getNeighbours(nextDeadEndField,width,height) == 3)
		{
			recursiveFill(nextDeadEndField, width, height);
			return true;
		}
		nextDeadEndField.second++;
	}


	if((x+1) >= width)
	{
		nextDeadEndField.first++;
		if(getNeighbours(nextDeadEndField,width,height) == 3)
		{
			recursiveFill(nextDeadEndField, width, height);
			return true;
		}
		nextDeadEndField.first--;
	}


	if((y+1) >= height)
	{
		nextDeadEndField.second++;
		if(getNeighbours(nextDeadEndField,width,height) == 3)
		{
			recursiveFill(nextDeadEndField, width, height);
			return true;
		}
		nextDeadEndField.second--;
	}

	return false;

}


void DeadEndFiller::turnAndMove()
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
		if(maze->passable(targetPosition) && (!maze->isMarked(targetPosition,'D')))
		{
			move(targetPosition);
			return;
		}
		else
		{
			this->dir = (this->dir+1) %4;
		}
	}
}

void DeadEndFiller::move(std::pair<int,int> targetPosition)
{
	maze->mark(this->pos,'L');
	this->pos = targetPosition;
	maze->mark(this->pos,'X');
}










