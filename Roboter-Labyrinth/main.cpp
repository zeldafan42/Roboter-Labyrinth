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
#include <memory>

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


		std::shared_ptr<Linksdreher> ld;
		std::shared_ptr<DeadEndFiller> def;
		std::shared_ptr<BreadthFirstSearch> bfs;


		for(i = 0; i<3; i++)
		{

			if(robotsInUse[i])
			{
				switch(i)
				{
				case 0:
						{
							ld = std::make_shared<Linksdreher>(Linksdreher(maze));
							ld->printSolution();
							ld->printSteps();
						}
						break;

				case 1:
						{
							def = std::make_shared<DeadEndFiller>(DeadEndFiller(maze));
							def->printSolution();
							def->printSteps();
						}
						break;

				case 2:
						{
							bfs = std::make_shared<BreadthFirstSearch>(BreadthFirstSearch(maze));
							bfs->printSolution();
							bfs->printSteps();
						}
				break;
				default:
						break;
				}
			}
		}
		cout << endl;
		cout << "--------------------------------------" << endl;
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
							ld->printResult();
						}
						break;

				case 1:
						{
							cout << "|   1   | ";
							def->printResult();
						}
						break;

				case 2:
						{
							cout << "|   2   | ";
							bfs->printResult();
						}
				break;
				default:
						break;
				}
			}
		}
		cout << "--------------------------------------" << endl;
		cout << endl;
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

