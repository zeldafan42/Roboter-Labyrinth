/*
 * Linksdreher.hpp
 *
 *  Created on: 23.05.2015
 *      Author: Zombieranke
 */

#ifndef LINKSDREHER_HPP_
#define LINKSDREHER_HPP_

#include "Robot.hpp"
#include <utility>


class Linksdreher : public Robot {
public:
	Linksdreher(const Maze& maze);
	virtual ~Linksdreher();
	void findSolution();
	void printResult();

private:
	void turnAndMove();
	void move(std::pair<int,int> targetPosition);
};

#endif /* LINKSDREHER_HPP_ */
