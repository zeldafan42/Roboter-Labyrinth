/*
 * Linksdreher.h
 *
 *  Created on: 23.05.2015
 *      Author: Zombieranke
 */

#ifndef LINKSDREHER_H_
#define LINKSDREHER_H_

#include "Robot.hpp"
#include <utility>


class Linksdreher: public Robot {
public:
	Linksdreher();
	virtual ~Linksdreher();
	Maze& solve();
};

#endif /* LINKSDREHER_H_ */
