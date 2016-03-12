/***************************************************
 * Program Filename: fish.cpp
 * Author: Chewie Lin
 * Date: 12 Feb 2016
 * Description:fish class functions 
***************************************************/
#include "fish.hpp"
#include "creature.hpp"
#include <string>
#include <cstdlib>
#include <iostream>

/*****************************************
 * Function: Fish()
 * Description: default constructor
 ******************************************/
Fish::Fish() {
		name = "Fish";
		status = true;
		type = 1;
		strength = 12;
		maxStrength = strength;
		armor = 0;
		nDieAttack = 2;
		nFaceAttack = 6;
		nDieDefend = 2;
		nFaceDefend = 6;
}

/*****************************************
 * Function: attack();
 * Description: fish attack();
 ******************************************/
int Fish::attack( Creature *opponent) {
		return roll(nDieAttack, nFaceAttack);
}

/*****************************************
 * Function: defend()
 * Description: fish defend function
 ******************************************/
int Fish::defend( Creature *opponent, int attackPt) {
	bool charm = rand() % 2;
	if ( charm == true ) {
		std::cout << " ***** Fish used evasion" << std::endl;
		return 0;
	}
	else if ( strength <= 0) {
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
