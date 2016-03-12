/*****************************************
* Program Filename: forest.hpp
* Author: Chewie Lin
* Date: 12 Mar 2016
* Description: forest class prototypes
*****************************************/
#ifndef FOREST_HPP
#define FOREST_HPP
#include <list>
#include "space.hpp"
#include "creature.hpp"
#include "game.hpp"
#include "bird.hpp"
#include "mountain.hpp"

class Forest: public Space {
	protected:
		std::string s;
		//std::list<Creature> animal;
	public:
		Forest(Space*);
		~Forest();
		void gather(Creature*,std::list<Item>&);
		void battle(Creature*,std::list<Item>&);
		void getFile();
		Space* getDir(std::string);
};
#endif
