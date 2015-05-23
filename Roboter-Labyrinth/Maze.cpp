/*
 * Maze.cpp
 *
 *  Created on: 23.05.2015
 *      Author: Christine
 */

#include "Maze.hpp"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

Maze::Maze(const std::string& filename)
{
	int fieldSizeX = 0;
	int fieldSizeY = 0;
	int toFindCount = 2;

	ifstream fin(filename);

	string line;

	while(getline(fin, line))
	{
		if(line.length() > 0)
		{
			field.push_back(line);
		}
	}


	if(!field.empty())
	{
		fieldSizeX = field.at(0).length();
		fieldSizeY = field.size();


		toFindCount = this->searchForExits(0,0,1,0,fieldSizeX,fieldSizeY,toFindCount);
		toFindCount = this->searchForExits(fieldSizeX-1,0,0,1,fieldSizeX,fieldSizeY,toFindCount);
		toFindCount = this->searchForExits(fieldSizeX-1,fieldSizeY-1,-1,0,fieldSizeX,fieldSizeY,toFindCount);
		toFindCount = this->searchForExits(0,fieldSizeY-1,0,-1,fieldSizeX,fieldSizeY,toFindCount);

		cout << "Start: " << start.first << ", " << start.second << endl;
		cout << "End: " << end.first << ", " << end.second << endl;

	}
}

Maze::~Maze()
{
	// TODO Auto-generated destructor stub
}

std::pair<int, int> Maze::getStart() const
{
	return start;
}

std::pair<int, int> Maze::getEnd() const
{
	return end;
}

bool Maze::passable(std::pair<int, int> pair) const
{
	if(pair.first >= field.at(0).length() || pair.first < 0 || pair.second >= field.size() || pair.second < 0 )
	{
		return false;
	}
	else if(field.at(pair.second).at(pair.first) != ' ')
	{
		return false;
	}
	else
	{
		return true;
	}
}


int Maze::searchForExits(int x, int y, int xInc, int yInc, int endX, int endY, int count)
{
	bool endReached = false;
	while(!endReached)
	{
		if(count > 1)
		{
			if(field.at(y).at(x) == ' ')
			{
				start.first = x;
				start.second = y;
				count--;
			}
		}
		else if(count > 0)
		{
			if(field.at(y).at(x) == ' ')
			{
				end.first = x;
				end.second = y;
				return 0;
			}
		}
		else
		{
			return 0;
		}

		x += xInc;
		y += yInc;

		if(x >= endX || y >= endY)
		{
			endReached = true;
		}
	}
	return count;
}

void Maze::mark(std::pair<int, int> pair, char marker)
{
	field.at(pair.first).at(pair.second) = marker;
}

Maze::Maze(const Maze& maze)
{
	field = maze.field;
}

void Maze::printMaze() const
{
	for( size_t i = 0; i < field.size(); ++i )
	{
		cout << field[i] << endl;
	}
}
