/*
 * BreadthFirstSearch.h
 *
 *  Created on: 24.05.2015
 *      Author: Christine
 */

#ifndef BREADTHFIRSTSEARCH_HPP_
#define BREADTHFIRSTSEARCH_HPP_

#include "Robot.hpp"

class BreadthFirstSearch: public Robot
{
public:
	BreadthFirstSearch(const Maze& maze);
	virtual ~BreadthFirstSearch();
	void printSolution();
	void printResult();
};

#endif /* BREADTHFIRSTSEARCH_HPP_ */
