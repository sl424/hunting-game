/***************************************************
 * Program Filename: mountain.cpp
 * Author: Chewie Lin
 * Date: 12 Mar 2016
 * Description:mountain class functions 
***************************************************/
#include "mountain.hpp"

/*****************************************
 * Function: mountain()
 * Description: default constructor
 * no item or animal, return all pointer to previous
 ******************************************/
Mountain::Mountain(Space* previous){
	std::string s = "fish.txt";
	spaceName = "Mountain";
	msgIntro = "Intro";
	//resource.push_back(Item("water"));
	animal = NULL;

	ePtr = previous;
	nPtr = previous;
	sPtr = previous;
	wPtr = previous;
}


/*****************************************
 * Function: mountain()
 * Description: default destuctor
 ******************************************/
Mountain::~Mountain(){
}

/*****************************************
 * Function: gather()
 * Description: acquire item; may be attacked by animal
 ******************************************/
void Mountain::gather(Creature* hunter, std::list<Item> &backpack){
	if ( resource.empty() ) 
		std::cout << "No resource found " << std::endl;
	else {
	std::cout << "Scooping " << resource.front().whatami() << "...\n";
	backpack.push_back(resource.front());
	//50% chance of getting attack by snake
	if ( animal->roll(1,2) == 1 
			&& animal->getStrength() > 0 ) {
		std::cout << "Oh no! An animal attacked you ...\n";
		hunter->defend(animal, animal->attack(hunter));
	}
	}
}


/*****************************************
 * Function: battle()
 * Description: attack the animal
 ******************************************/
void Mountain::battle(Creature* hunter, std::list<Item> &backpack){
	if ( animal == NULL )
		std::cout << "No animal found" << std::endl;
	else if (animal->getStrength() <= 0){
		std::cout << animal->getName() << "is killed" 
			<< std::endl;
		char gather;
		std::cout << "Take some animal meat? (y/n): ";
		std::cin >> gather;
		if ( gather == 'y' )
			backpack.push_back(Item(animal->getName()));
	}
	else {
		int a = hunter->attack(animal);
		animal->defend(hunter,a);
	}
}


/*****************************************
 * Function: getDir()
 * Description: return the address
 ******************************************/
Space* Mountain::getDir(std::string dir){
	if ( dir == "east" )
		return ePtr;
	if ( dir == "west" )
		return wPtr;
	if ( dir == "north" )
		return nPtr;
	if ( dir == "south" )
		return sPtr;
}


/*****************************************
 * Function: getFile()
 * Description: print the ascii art
 ******************************************/
void Mountain::getFile() {
	std::string s = "mountain.txt";
	showGraphics(s);
}
