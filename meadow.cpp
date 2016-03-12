/***************************************************
 * Program Filename: meadow.cpp
 * Author: Chewie Lin
 * Date: 12 Mar 2016
 * Description:meadow class functions 
***************************************************/
#include "meadow.hpp"

/*****************************************
 * Function: meadow()
 * Description: default constructor
 * initialise all the surrounding spaces and items
 ******************************************/
Meadow::Meadow(Space* previous){
	std::string s = "bison.txt";
	spaceName = "Meadow";
	msgIntro = "Intro";
	
	resource.push_back(Item("mushroom"));
	animal = new Snake();

	nPtr = previous;
	wPtr = new Mountain(this);
	sPtr = new Mountain(this);
	ePtr = new Mountain(this);
}

/*****************************************
 * Function: meadow()
 * Description: default destuctor
 ******************************************/
Meadow::~Meadow(){
}

/*****************************************
 * Function: gather()
 * Description: acquire item; may be attacked by animal
 ******************************************/
void Meadow::gather(Creature* hunter, std::list<Item> &backpack){
	std::cout << "Picking " << resource.front().whatami() << "...\n";
	backpack.push_back(resource.front());
	//50% chance of getting attack by snake
	if ( animal->roll(1,2) == 1 
			&& animal->getStrength() > 0 ) {
		std::cout << "Oh no! An animal attacked you ...\n";
		hunter->defend(animal, animal->attack(hunter));
	}
}

/*****************************************
 * Function: battle()
 * Description: attack the animal
 ******************************************/
void Meadow::battle(Creature* hunter, std::list<Item> &backpack){
	if (animal->getStrength() <= 0){
		std::cout << animal->getName() << " is killed" 
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
Space* Meadow::getDir(std::string dir){
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
void Meadow::getFile() {
	std::string s = "snake.txt";
	showGraphics(s);
}
