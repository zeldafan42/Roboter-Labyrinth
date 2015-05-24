/*
 * DeadEndFiller.hpp
 *
 *  Created on: 24.05.2015
 *      Author: Zombieranke
 */

#ifndef DEADENDFILLER_HPP_
#define DEADENDFILLER_HPP_

#include "Robot.hpp"
#include <utility>

class DeadEndFiller : public Robot {
public:
	DeadEndFiller(const Maze& maze);
	virtual ~DeadEndFiller();
	void printSolution();
	void printSteps();

private:
	int fillDeadEnds();
	int getNeighbours(std::pair<int,int>currentField, int width, int height);
	bool recursiveFill(std::pair<int,int>currentField, int width, int height);
	void turnAndMove();
	void move(std::pair<int,int> targetPosition);
};

#endif /* DEADENDFILLER_HPP_ */
