/*****************************************
* Program Filename: snake.hpp
* Author: Chewie Lin
* Date: 12 Feb 2016
* Description: snake class prototypes
*****************************************/

#ifndef SNAKE_HPP
#define SNAKE_HPP
#include "creature.hpp"
#include <string>

class Snake:public Creature {
	protected:
	public:
		Snake();
		int attack( Creature* );
		int defend( Creature* , int);
};
#endif
