/*****************************************
* Program Filename: fish.hpp
* Author: Chewie Lin
* Date: 12 Feb 2016
* Description: fish class prototypes
*****************************************/
#ifndef FISH_HPP
#define FISH_HPP
#include "creature.hpp"
#include <string>

class Fish:public Creature {
	protected:
	public:
		Fish();
		int attack( Creature* );
		int defend( Creature* , int);
};
#endif
