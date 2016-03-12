/*****************************************
* Program Filename: campground.hpp
* Author: Chewie Lin
* Date: 12 Mar 2016
* Description: campground class prototypes
*****************************************/
#ifndef CAMPGRD_HPP
#define CAMPGRD_HPP
#include <list>
#include "space.hpp"
#include "forest.hpp"
#include "lake.hpp"
#include "river.hpp"
#include "meadow.hpp"
#include "creature.hpp"
#include "game.hpp"
#include "snake.hpp"

class Campground: public Space {
	protected:
		std::string s;
		//std::list<Creature> animal;
	public:
		Campground();
		~Campground();
		void gather(Creature*,std::list<Item>&);
		void battle(Creature*,std::list<Item>&);
		void getFile();
		Space* getDir(std::string);
};
#endif
