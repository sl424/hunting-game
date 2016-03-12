/***************************************************
 * Program Filename: creature.cpp
 * Author: Chewie Lin
 * Date: 12 Feb 2016
 * Description:creature class functions 
***************************************************/
#include "creature.hpp"
#include <ctime>
#include <cstdlib>

/*****************************************
 * Function: heal()
 * Description: restore some strength
 ******************************************/
int Creature::heal() {
	int restore = (maxStrength-strength)*0.5;
	strength += restore;
	return restore;
}

/*****************************************
 * Function: killed()
 * Description: KO hit
 ******************************************/
bool Creature::killed() {
strength = 0;
	status = false;
	return status;
}

/*****************************************
 * Function: roll()
 * Description: roll the die(s)
 ******************************************/
int Creature::roll(int nDie, int nFace) {
	int sum = 0;
	for ( int i = 0; i < nDie; i++ ) {
		int result = 1 + rand() % nFace;
		sum += result;
	}
	return sum;
}

/*****************************************
 * Function: getStrength()
 * Description: return the strength value
 ******************************************/
int Creature::getStrength(){
	return strength;
}

/*****************************************
 * Function: getName()
 * Description: return the creature name
 ******************************************/
std::string Creature::getName() {
	return name;
}

/*****************************************
 * Function: getTeam()
 * Description: return the creature team
 ******************************************/
std::string Creature::getTeam() {
	return team;
}

/*****************************************
 * Function: setName()
 * Description: set the creature name
 ******************************************/
void Creature::setName() {
	std::string nickname;
	std::cout << "Enter Name: ";
	std::cin >> nickname;
	name += nickname;
	name += " ";
}

/*****************************************
 * Function: setTeam()
 * Description:set the creature team
 ******************************************/
void Creature::setTeam(std::string &name) {
	team = name;
}


/*****************************************
 * Function: attack()
 * Description: basic attack function
 ******************************************/
int Creature::attack() {
	return roll(nDieAttack, nFaceAttack);
}
