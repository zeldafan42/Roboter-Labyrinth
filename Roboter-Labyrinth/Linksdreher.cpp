/*
 * Linksdreher.cpp
 *
 *  Created on: 23.05.2015
 *      Author: Zombieranke
 */

#include "Linksdreher.hpp"
#include <utility>


Linksdreher::Linksdreher(const Maze& maze) : Robot(maze, "Linksdreher")
{
}

Linksdreher::~Linksdreher()
{
}

void Linksdreher::findSolution()
{
	steps = 0;
	this->pos = maze->getStart();

	while(pos != maze->getEnd())
	{
		turnAndMove();
	}

	maze->printMaze();

	printSteps();
}

void Linksdreher::printResult()
{
	int digits = countDigits(steps);
	int i = 0;

	std::cout << name <<"        |";

	for(i=0;i<((7-digits)/2);i++)
	{
		std::cout <<" ";
	}
	std::cout << steps;

	for(i=0;i<((7-digits)/2);i++)
	{
		std::cout <<" ";
	}

	if(((7-digits)%2) == 1)
	{
		std::cout <<" ";
	}

	std::cout <<"|" << std::endl;
}

void Linksdreher::turnAndMove()
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
			return;
		}
		else
		{
			this->dir = (this->dir+1) %4;

		}
	}
}

void Linksdreher::move(std::pair<int,int> targetPosition)
{
	steps++;
	maze->mark(this->pos,'L');
	this->pos = targetPosition;
	maze->mark(this->pos,'X');
}





















