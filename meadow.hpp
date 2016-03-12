/*****************************************
* Program Filename: meadow.hpp
* Author: Chewie Lin
* Date: 12 Mar 2016
* Description: meadow class prototypes
*****************************************/
#ifndef MEADOW_HPP
#define MEADOW_HPP
#include <list>
#include "space.hpp"
#include "creature.hpp"
#include "game.hpp"
#include "snake.hpp"
#include "mountain.hpp"

class Meadow: public Space {
	protected:
		std::string s;
		//std::list<Creature> animal;
	public:
		Meadow(Space*);
		~Meadow();
		void gather(Creature*,std::list<Item>&);
		void battle(Creature*,std::list<Item>&);
		void getFile();
		Space* getDir(std::string);
};
#endif
