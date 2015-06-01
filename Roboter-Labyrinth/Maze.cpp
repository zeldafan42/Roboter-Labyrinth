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
#include <algorithm>

using namespace std;

Maze::Maze(const std::string& filename)
{
	int toFindCount = 2;

	ifstream fin(filename);

	string line;

	while(getline(fin, line))
	{
		line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
		line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
		if(line.length() > 0)
		{
			field.push_back(line);
		}
	}


	if(!field.empty())
	{
		fieldSize.first = field.at(0).length();
		fieldSize.second = field.size();


		toFindCount = this->searchForExits(0,0,1,0,fieldSize.first,0,toFindCount);
		toFindCount = this->searchForExits(fieldSize.first-1,0,0,1,fieldSize.first-1,fieldSize.second,toFindCount);
		toFindCount = this->searchForExits(fieldSize.first-1,fieldSize.second-1,-1,0,0,fieldSize.second-1,toFindCount);
		toFindCount = this->searchForExits(0,fieldSize.second-1,0,-1,0,0,toFindCount);

		if(toFindCount > 0)
		{
			cerr << "Could not find entrance/exit" << endl;
			exit(-1);
		}

		cout << "Start: " << start.first << ", " << start.second << endl;
		cout << "End: " << end.first << ", " << end.second << endl;

	}
	else
	{
		cerr << "Something went wrong while parsing maze file" << endl << "Check your file!" << endl;
		exit(-1);
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

std::pair<int,int> Maze::getBounds() const
{
	return fieldSize;
}

char Maze::getMark(std::pair<int, int> pair) const
{
	if(pair.first >= fieldSize.first || pair.first < 0 || pair.second >= fieldSize.second || pair.second < 0 )
	{
		return 'E';
	}

	return field.at(pair.second).at(pair.first);
}

void Maze::clearMark(char mark)
{
	for(auto fIt = field.begin(); fIt != field.end(); ++fIt)
	{
		for(auto sIt = fIt->begin(); sIt != fIt->end(); ++sIt)
		{
			if(*sIt == mark)
			{
				*sIt = ' ';
			}
		}
	}
}

bool Maze::passable(std::pair<int, int> pair) const
{
	if(pair.first >= fieldSize.first || pair.first < 0 || pair.second >= fieldSize.second || pair.second < 0 )
	{
		return false;
	}
	else if(field.at(pair.second).at(pair.first) == '#')
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Maze::isMarked(std::pair<int, int> pair, char mark) const
{
	if(pair.first >= fieldSize.first || pair.first < 0 || pair.second >= fieldSize.second || pair.second < 0 )
	{
		return false;
	}
	else if(field.at(pair.second).at(pair.first) == mark)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Maze::isMarked(std::pair<int, int> pair) const
{
	if(pair.first >= fieldSize.first || pair.first < 0 || pair.second >= fieldSize.second || pair.second < 0 )
	{
		return false;
	}
	else if(field.at(pair.second).at(pair.first) != ' ')
	{
		return true;
	}
	else
	{
		return false;
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

		if(x == endX && y == endY)
		{
			endReached = true;
		}
	}
	return count;
}

void Maze::mark(std::pair<int, int> pair, char marker)
{
	if(pair.first >= fieldSize.first || pair.first < 0 || pair.second >= fieldSize.second || pair.second < 0 )
	{
		cerr << "Cannot mark outside of the maze!";
	}
	else
	{
		field.at(pair.second).at(pair.first) = marker;
	}
}

/*Maze::Maze(const Maze& maze)
{
	field = maze.field;
	start = maze.start;
	end = maze.end;
}*/

void Maze::printMaze() const
{
	for( size_t i = 0; i < field.size(); ++i )
	{
		cout << field[i] << endl;
	}
	cout << endl;
}
