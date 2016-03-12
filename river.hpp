/*****************************************
* Program Filename: river.hpp
* Author: Chewie Lin
* Date: 12 Mar 2016
* Description: river class prototypes
*****************************************/
#ifndef RIVER_HPP
#define RIVER_HPP
#include <list>
#include "space.hpp"
#include "creature.hpp"
#include "game.hpp"
#include "bird.hpp"
#include "mountain.hpp"

class River: public Space {
	protected:
		std::string s;
		//std::list<Creature> animal;
	public:
		River(Space*);
		~River();
		void gather(Creature*,std::list<Item>&);
		void battle(Creature*,std::list<Item>&);
		void getFile();
		Space* getDir(std::string);
};
#endif
