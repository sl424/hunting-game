/*****************************************
* Program Filename: human.hpp
* Author: Chewie Lin
* Date: 12 Feb 2016
* Description: human class prototypes
*****************************************/
#ifndef HUMAN_HPP
#define HUMAN_HPP
#include "creature.hpp"
#include <string>

class Human:public Creature {
	protected:
	public:
		Human();
		int attack( Creature* );
		int defend( Creature* , int);
};
#endif
