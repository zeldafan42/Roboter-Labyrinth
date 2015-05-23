/*
 * main.cpp
 *
 *  Created on: 23.05.2015
 *      Author: Zombieranke
 */

#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <getopt.h>
#include "Maze.hpp"

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
	Maze maze(argv[optind]);

}



void printUsage()
{
	fprintf(stderr, "Usage: labrob FILENAME [-t1] [-t2] ... [-tn]\n");
	exit(1);
}

