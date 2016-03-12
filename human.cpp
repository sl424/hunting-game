/***************************************************
 * Program Filename: human.cpp
 * Author: Chewie Lin
 * Date: 12 Feb 2016
 * Description:human class functions 
***************************************************/
#include "human.hpp"
#include "creature.hpp"
#include <string>
#include <cstdlib>

/*****************************************
 * Function: Human()
 * Description: default constructor
 ******************************************/
Human::Human() {
		name = " You ";
		status = true;
		type = 1;
		strength = 12;
		maxStrength = strength;
		armor = 0;
		nDieAttack = 4;
		nFaceAttack = 6;
		nDieDefend = 1;
		nFaceDefend = 2;
}

/*****************************************
 * Function: attack();
 * Description: human attack();
 ******************************************/
int Human::attack( Creature *opponent) {
		return roll(nDieAttack, nFaceAttack);
}

/*****************************************
 * Function: defend()
 * Description: human defend function
 ******************************************/
int Human::defend( Creature *opponent, int attackPt) {
	if ( strength <= 0) {
		return 0;
	}
	else {
		int damage;
		int defend = roll(nDieDefend, nFaceDefend);
		damage = attackPt - armor - defend;
		if ( damage > 0 ) {
			strength -= damage;
			std::cout << name << "took " << damage
				<< " damage points " << std::endl;
		}
		return defend;
	}
}
