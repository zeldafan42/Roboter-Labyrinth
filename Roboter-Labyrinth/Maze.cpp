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
	ifstream fin(filename);

	vector<string> v;

	string line;

	while(getline(fin, line))
	{
		v.push_back(line);
	}

	// show all the words, here 'inside single quote delimiters'

	for( size_t i = 0; i < v.size(); ++i )
	{
		cout << v[i] << endl;
	}

}

Maze::~Maze()
{
	// TODO Auto-generated destructor stub
}

