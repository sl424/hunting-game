/*****************************************
* Program Filename: mountain.hpp
* Author: Chewie Lin
* Date: 12 Mar 2016
* Description: mountain class prototypes
*****************************************/
#ifndef MOUNTAIN_HPP
#define MOUNTAIN_HPP
#include <list>
#include "space.hpp"
#include "creature.hpp"
#include "game.hpp"
#include "fish.hpp"

class Mountain: public Space {
	protected:
		std::string s;
		//std::list<Creature> animal;
	public:
		Mountain(Space*);
		~Mountain();
		void gather(Creature*,std::list<Item>&);
		void battle(Creature*,std::list<Item>&);
		void getFile();
		Space* getDir(std::string);
};
#endif
