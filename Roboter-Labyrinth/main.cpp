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
#include "Robot.hpp"
#include "Linksdreher.hpp"
#include "DeadEndFiller.hpp"

using namespace std;

void printUsage();

int main(int argc,char* argv[])
{
	int c = 0;
	int i = 0;
	int robotNumber = 0;
	bool robotsInUse[3] = {0,0,0};

	while( (c = getopt(argc, argv, "t:h")) != EOF )
	{
		switch(c)
		{
		case 't':	robotNumber = (int) strtol(optarg, NULL, 0);

					if(robotNumber>3 || robotNumber < 1)
					{
						cout << "Robot #" << robotNumber << " not in use";
					}

					robotsInUse[robotNumber-1] = true;

					break;

		case 'h':	printUsage();
					break;

		default:	assert(0);
					break;
		}
	}

	if(argc == optind + 1)
	{
		Maze maze(argv[optind]);
		maze.printMaze();

		for(i = 0; i<3; i++)
		{
			if(robotsInUse[i])
			{
				switch(i)
				{
				case 0:
						cout << "Starting robot" << i+1 <<endl;
						{
							Linksdreher l1(maze);
							l1.printSolution();
							l1.printSteps();
						}
						break;

				case 1:
						cout << "Starting robot" << i+1 <<endl;
						{
							DeadEndFiller d1(maze);
							d1.printSolution();
							d1.printSteps();
						}
						break;
				default:
						break;
				}
			}
		}
	}
	else
	{
		printUsage();
	}

}



void printUsage()
{
	fprintf(stderr, "Usage: labrob FILENAME [-t1] [-t2] ... [-tn]\n");
	exit(1);
}

