/***************************************************
 * Program Filename: river.cpp
 * Author: Chewie Lin
 * Date: 12 Mar 2016
 * Description:river class functions 
***************************************************/
#include "river.hpp"

/*****************************************
 * Function: forest()
 * Description: default constructor
 * initialise all the surrounding spaces
 * and items
 ******************************************/
River::River(Space* previous){
	std::string s = "bat.txt";
	spaceName = "River";
	msgIntro = "Intro";
	resource.push_back(Item("water"));
	animal = new Bird();

	sPtr = previous;
	nPtr = new Mountain(this);
	wPtr = new Mountain(this);
	ePtr = new Mountain(this);
}


/*****************************************
 * Function: river()
 * Description: default destuctor
 ******************************************/
River::~River(){
}


/*****************************************
 * Function: gather()
 * Description: acquire item; may be attacked by animal
 ******************************************/
void River::gather(Creature* hunter, std::list<Item> &backpack){
	std::cout << "Scooping " << resource.front().whatami() << "...\n";
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
void River::battle(Creature* hunter, std::list<Item> &backpack){
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
Space* River::getDir(std::string dir){
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
void River::getFile() {
	std::string s = "bat.txt";
	showGraphics(s);
}
