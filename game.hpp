/*****************************************
* Program Filename: game.hpp
* Author: Chewie Lin
* Date: 12 Mar 2016
* Description: game class prototypes
*****************************************/
#ifndef GAME_HPP
#define GAME_HPP
#include "state.hpp"
#include "campground.hpp"
#include "space.hpp"
#include <algorithm>
#include "creature.hpp"
#include "human.hpp"
#include <fstream>
class Game {
	protected:
		bool mComplete;
		int time;
		Space* whereami;
		Creature* hunter;
		std::list<Item> backpack;
		int max_backsize;
		std::list<Item> mission;
		std::list<Item> progress;
	public:
		Game();
		~Game();
		void goNext();
		void showStat();
		void doAction(char c);
		void showAction();
		bool askAction();
		void showList(std::list<Item>);
		void setLocation(std::string);
		void setMission();
		void showMission();
		void showBag();
		void updateList(std::list<Item>&);
		void gameOver();
		void discardItem();
		void checkBagSize();
		void updateProgress();
};

#endif
