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
				didFill = true;
				recursiveFill(std::make_pair(i,j), width, height);
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


void DeadEndFiller::recursiveFill(std::pair<int,int>currentField, int width, int height)
{
	std::pair<int, int> nextDeadEndField = currentField;
	int x = currentField.first;
	int y = currentField.second;

	maze->mark(currentField,'D');

	if((x-1) >= 0)
	{
		nextDeadEndField.first--;
		if(getNeighbours(nextDeadEndField,width,height) == 3)
		{
			recursiveFill(nextDeadEndField, width, height);
			return;
		}
		nextDeadEndField.first++;
	}


	if((y-1) >= 0)
	{
		nextDeadEndField.second--;
		if(getNeighbours(nextDeadEndField,width,height) == 3)
		{
			recursiveFill(nextDeadEndField, width, height);
			return;
		}
		nextDeadEndField.second++;
	}


	if((x+1) >= width)
	{
		nextDeadEndField.first++;
		if(getNeighbours(nextDeadEndField,width,height) == 3)
		{
			recursiveFill(nextDeadEndField, width, height);
			return;
		}
		nextDeadEndField.first--;
	}


	if((y+1) >= height)
	{
		nextDeadEndField.second++;
		if(getNeighbours(nextDeadEndField,width,height) == 3)
		{
			recursiveFill(nextDeadEndField, width, height);
			return;
		}
		nextDeadEndField.second--;
	}


}













