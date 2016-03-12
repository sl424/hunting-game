/*****************************************
* Program Filename: lake.hpp
* Author: Chewie Lin
* Date: 12 Mar 2016
* Description: lake class prototypes
*****************************************/
#ifndef LAKE_HPP
#define LAKE_HPP
#include <list>
#include "space.hpp"
#include "creature.hpp"
#include "game.hpp"
#include "fish.hpp"
#include "mountain.hpp"

class Lake: public Space {
	protected:
		std::string s;
		//std::list<Creature> animal;
	public:
		Lake(Space*);
		~Lake();
		void gather(Creature*,std::list<Item>&);
		void battle(Creature*,std::list<Item>&);
		void getFile();
		Space* getDir(std::string);
};
#endif
