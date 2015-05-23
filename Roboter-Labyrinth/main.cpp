/*
 * main.cpp
 *
 *  Created on: 23.05.2015
 *      Author: Zombieranke
 */

#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <getopt.h>

using namespace std;

void printUsage();

int main(int argc,char* argv[])
{
	int c = 0;
	int robotNumber = 0;
	bool robotsInUse[3] = {0,0,0};

	while( (c = getopt(argc, argv, "t:h")) != EOF )
	{
		switch(c)
		{
		case 't':	robotNumber = (int) strtol(optarg, NULL, 0);

					robotsInUse[robotNumber] = true;

					break;

		case 'h':	printUsage();
					break;

		default:	assert(0);
					break;
		}
	}

	FILE* filePointer = fopen(argv[1], "r");

	ifstream fin( argv[1] );

	vector <string> v;
	int read = 0;

	string line;
	char* forFgets;

	while(getline(fin, line) != -1)
	{
		read = getline(fin, line)
		string word = fgets(forFgets, read, filePointer);
		v.push_back(word);
	}

	// show all the words, here 'inside single quote delimiters'

	for( size_t i = 0; i < v.size(); ++i )
	{
		cout << v[i] << endl;
	}
}



void printUsage()
{
	fprintf(stderr, "Usage: gridserver -x INT>0 -y INT>0\n");
	exit(1);
}

