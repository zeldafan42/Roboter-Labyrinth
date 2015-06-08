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
#include <forward_list>
#include <getopt.h>
#include "Maze.hpp"
#include "Robot.hpp"
#include "Linksdreher.hpp"
#include "DeadEndFiller.hpp"
#include "BreadthFirstSearch.hpp"
#include <memory>
#include <thread>
#include <mutex>

using namespace std;

void printUsage();

int main(int argc,char* argv[])
{
	int c = 0;
	mutex m;
	int i = 0;
	int robotNumber = 0;
	forward_list<std::shared_ptr<Robot> > robotList;

	if(argc < 2)
	{
		printUsage();
	}
	Maze maze(argv[1]);


	while( (c = getopt(argc, argv, "t:h")) != EOF )
	{
		switch(c)
		{
		case 't':	
			robotNumber = (int) strtol(optarg, NULL, 0);

			switch(robotNumber-1)
			{
			case 0:
				robotList.push_front(std::shared_ptr<Robot>(new Linksdreher(maze)));
				break;

			case 1:

				robotList.push_front(std::shared_ptr<Robot>(new DeadEndFiller(maze)));
				break;

			case 2:
				robotList.push_front(std::shared_ptr<Robot>(new BreadthFirstSearch(maze)));
				break;

			default:
				cout << "Robot #" << robotNumber << " not available";
				break;
			}

			break;

		case 'h':	
			printUsage();
			break;

		default:
			assert(0);
			break;
		}
	}

	if(argc == optind + 1)
	{
		if(robotList.empty())
		{
			robotList.push_front(std::shared_ptr<Robot>(new Linksdreher(maze)));
		}
		maze.printMaze();

		forward_list<std::thread> threads;

		for(auto it = robotList.begin(); it != robotList.end(); it++)
		{
			auto findSol = [it,&m]()
			{
				(*it)->findSolution();
				m.lock();
				(*it)->printMaze();
				m.unlock();
			};
			threads.push_front(std::thread(findSol));
		}

		for(auto it = threads.begin(); it != threads.end(); it++)

		{
			it->join();
		}

		threads.clear();

		cout << endl;

		cout << endl;
		cout << "  --------------------------------------" << endl;
		cout << "  | Number|    Roboter Name    | Steps |" << endl;
		cout << "  --------------------------------------" << endl;

		i = 0;

		for(auto it = robotList.begin(); it != robotList.end(); it++)
		{
			cout << "  |   " << i << "   | ";
			(*it)->printResult();
			i++;
		}

		robotList.clear();

		cout << "  --------------------------------------" << endl;

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
