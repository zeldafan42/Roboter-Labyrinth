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
#include "BreadthFirstSearch.hpp"

using namespace std;

void printUsage();

int main(int argc,char* argv[])
{
	int c = 0;
	int count = 0;
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
					count++;

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
		if(count == 0)
		{
			robotsInUse[0] = true;
		}
		Maze maze(argv[optind]);
		maze.printMaze();


		Linksdreher l1(maze);
		DeadEndFiller d1(maze);
		BreadthFirstSearch b1(maze);


		for(i = 0; i<3; i++)
		{

			if(robotsInUse[i])
			{
				switch(i)
				{
				case 0:
						{
							l1.printSolution();
							l1.printSteps();
						}
						break;

				case 1:
						{
							d1.printSolution();
							d1.printSteps();
						}
						break;

				case 2:
						{
							b1.printSolution();
							b1.printSteps();
						}
				break;
				default:
						break;
				}
			}
		}

		cout << "| Number|    Roboter Name    | Steps |" << endl;
		cout << "--------------------------------------" << endl;
		for(i = 0; i<3; i++)
		{
			if(robotsInUse[i])
			{
				switch(i)
				{
				case 0:
						{
							cout << "|   0   | ";
							l1.printResult();
						}
						break;

				case 1:
						{
							cout << "|   1   | ";
							d1.printResult();
						}
						break;

				case 2:
						{
							cout << "|   2   | ";
							b1.printResult();
						}
				break;
				default:
						break;
				}
			}
		}
		cout << "--------------------------------------" << endl;
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

