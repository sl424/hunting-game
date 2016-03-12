/*****************************************
* Program Filename: vampire.hpp
* Author: Chewie Lin
* Date: 12 Feb 2016
* Description: vampire class prototypes
*****************************************/
#ifndef BIRD_HPP
#define BIRD_HPP
#include "creature.hpp"
#include <string>

class Bird:public Creature {
	protected:
	public:
		Bird();
		int attack( Creature* );
		int defend( Creature* , int);
};
#endif
