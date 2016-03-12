/*****************************************
* Program Filename: creature.hpp
* Author: Chewie Lin
* Date: 12 Feb 2016
* Description: creature class prototypes
*****************************************/
#ifndef CREATURE_HPP
#define CREATURE_HPP
#include <string>
#include <iostream>

class Creature {
	protected:
		std::string name;
		std::string team;
		bool status;
		int type;
		int armor;
		int strength;
		int maxStrength;
		int nDieAttack;
		int nFaceAttack;
		int nDieDefend;
		int nFaceDefend;
	public:
		virtual bool killed();
		virtual int getStrength();
		virtual void setName();
		virtual void setTeam(std::string &);
		virtual std::string getTeam();
		virtual std::string getName();
		virtual int attack();
		virtual int attack( Creature* ) = 0;
		virtual int defend( Creature* , int) = 0;
		int roll(int nDie, int nFace);
		virtual int heal();
};

#endif
