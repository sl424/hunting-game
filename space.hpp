/*****************************************
* Program Filename: space.hpp
* Author: Chewie Lin
* Date: 12 Mar 2016
* Description: space class prototypes
*****************************************/
#ifndef SPACE_HPP
#define SPACE_HPP
#include <cstdlib>
#include <string>
#include <iostream>
#include "item.hpp"
#include <list>
#include "state.hpp"
#include "creature.hpp"

class Space{
	protected:
		Creature* animal;
		std::list<Item> resource;
		//std::list<Creature> animal;
		Space* nPtr;
		Space* sPtr;
		Space* ePtr;
		Space* wPtr;
		std::string spaceName;
		std::string msgIntro;
	public:
		Space();
		~Space();
		void find();
		void welcome();
		virtual void gather(Creature*, std::list<Item>&) = 0;
		virtual void battle(Creature*, std::list<Item>&) = 0;
		void showResource();
		void showAnimal();
		Creature* getAnimal();
		std::string getSpaceName();
		virtual void getFile() = 0;
		virtual Space* getDir(std::string) = 0;
};

#endif
