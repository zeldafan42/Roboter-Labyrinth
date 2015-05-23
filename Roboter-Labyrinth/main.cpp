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

using namespace std;

void printUsage();

int main(int argc,char* argv[])
{
	int c = 0;
	int robotNumber = 0;
	bool robotsInUse[3] = {0,0,0};

	ifstream fin(argv[1]);
	vector <string> v;
	string line;

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


	while(getline(fin, line))
	{
		v.push_back(line);
	}

	for( size_t i = 0; i < v.size(); ++i )
	{
		cout << v[i] << endl;
	}
}



void printUsage()
{
	fprintf(stderr, "Usage: labrob FILENAME [-t1] [-t2] ... [-tn]\n");
	exit(1);
}

