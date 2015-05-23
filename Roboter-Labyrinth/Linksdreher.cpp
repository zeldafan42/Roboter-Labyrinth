/*
 * Linksdreher.cpp
 *
 *  Created on: 23.05.2015
 *      Author: Zombieranke
 */

#include "Linksdreher.hpp"
#include <utility>

Linksdreher::Linksdreher()
{
	// TODO Auto-generated constructor stub

}

Linksdreher::~Linksdreher()
{
	// TODO Auto-generated destructor stub
}

Maze& solve()
{
	this.pos = maze.getStart();

	while(pos != maze.getEnd())
	{
		turnAndMove();
	}

	return this.maze;
}


void turnAndMove()
{
	bool leftFree = false;
	std::pair<int,int> targetPosition;

	switch(this.facing)
	{
		case 0: 	targetPosition = std::make_pair(std::get<0>(this.pos)-1,std::get<1>(this.pos));
					break;

		case 1:		targetPosition = std::make_pair(std::get<0>(this.pos),std::get<1>(this.pos)-1);
					break;

		case 2:		targetPosition = std::make_pair(std::get<0>(this.pos)+1,std::get<1>(this.pos));
					break;

		case 3:		targetPosition = std::make_pair(std::get<0>(this.pos),std::get<1>(this.pos)+1);
					break;

		default:	break;

	}

	leftFree = maze.passable(targetPosition);

	if(leftFree)
	{
		this.facing = (this.facing+3) %4; // turns left
		move(targetPosition);
		return;
	}
	else
	{
		switch(this.facing)
		{
			case 0:		targetPosition = std::make_pair(std::get<0>(this.pos),std::get<1>(this.pos)-1);
						break;

			case 1:		targetPosition = std::make_pair(std::get<0>(this.pos)+1,std::get<1>(this.pos));
						break;

			case 2:		targetPosition = std::make_pair(std::get<0>(this.pos),std::get<1>(this.pos)+1);
						break;

			case 3: 	targetPosition = std::make_pair(std::get<0>(this.pos)-1,std::get<1>(this.pos));
						break;

			default:	break;

		}
		if(maze.passable(targetPosition)) // Now looks in front of him
		{
			return; //keeps his facing direction
		}
		else
		{
			switch(this.facing)
			{
				case 0:		targetPosition = std::make_pair(std::get<0>(this.pos)+1,std::get<1>(this.pos));
							break;

				case 1:		targetPosition = std::make_pair(std::get<0>(this.pos),std::get<1>(this.pos)+1);
							break;

				case 2: 	targetPosition = std::make_pair(std::get<0>(this.pos)-1,std::get<1>(this.pos));
							break;

				case 3:		targetPosition = std::make_pair(std::get<0>(this.pos),std::get<1>(this.pos)-1);
							break;

				default:	break;

			}

			if(maze.passable(targetPosition)) // Now looks to the right
			{
				this.facing = (this.facing+1) %4; // turns right
				return;
			}
			else
			{
				this.facing = (this.facing+2) %4; //makes an U-turn
				return;
			}
		}
	}


}

void move(std::pair<int,int> targetPosition)
{
	maze.mark(this.pos,'L');
	this.pos = targetPosition;
	maze.mark(this.pos,'X');
}





















