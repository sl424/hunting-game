/***************************************************
 * Program Filename: snake.cpp
 * Author: Chewie Lin
 * Date: 12 Feb 2016
 * Description:snake class functions 
***************************************************/
#include "snake.hpp"
#include "creature.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

/*****************************************
 * Function: Snake()
 * Description: default constructor
 ******************************************/
Snake::Snake() {
		name = "Snake";
		status = true;
		type = 2;
		strength = 8;
		maxStrength = strength;
		armor = 3;
		nDieAttack = 2;
		nFaceAttack = 6;
		nDieDefend = 1;
		nFaceDefend = 6;
}

/*****************************************
 * Function: attack();
 * Description: snake attack();
 ******************************************/
int Snake::attack( Creature *opponent) {
	int glareRoll = roll(nDieAttack, nFaceAttack);
	if ( glareRoll == 12 ) {
		opponent->killed();
		std::cout << " ***** Snake used Glare" << std::endl;
		return glareRoll;
	}
	else {
		return glareRoll;
	}
}

/*****************************************
 * Function: defend()
 * Description: snake defend function
 ******************************************/
int Snake::defend( Creature *opponent, int attackPt) {
	if ( strength <= 0) {
		return 0;
	}
	else {
		int damage;
		int defend = roll(nDieDefend, nFaceDefend);
		damage = attackPt - armor - defend;
		if ( damage > 0 ) {
			strength -= damage;
			std::cout << name << " took " << damage 
				<< " damage points "<< std::endl;
		}
		else
			std::cout << "No damage" << std::endl;
		return defend;
	}
}
