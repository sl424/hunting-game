/***************************************************
 * Program Filename: bird.cpp
 * Author: Chewie Lin
 * Date: 12 Feb 2016
 * Description:bird class functions 
***************************************************/
#include "bird.hpp"
#include "creature.hpp"
#include <string>
#include <cstdlib>
#include <iostream>

/*****************************************
 * Function: Bird()
 * Description: default constructor
 ******************************************/
Bird::Bird() {
		name = "Bird";
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
 * Description: bird attack();
 ******************************************/
int Bird::attack( Creature *opponent) {
		return roll(nDieAttack, nFaceAttack);
}

/*****************************************
 * Function: defend()
 * Description: bird defend function
 ******************************************/
int Bird::defend( Creature *opponent, int attackPt) {
	bool charm = rand() % 2;
	if ( charm == true ) {
		std::cout << " ***** Bird used evasion" << std::endl;
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
