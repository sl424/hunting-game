/***************************************************
 * Program Filename: campground.cpp
 * Author: Chewie Lin
 * Date: 12 Mar 2016
 * Description:campground class functions 
***************************************************/
#include "campground.hpp"


/*****************************************
 * Function: Campground()
 * Description: default constructor
 * initialise all the surrounding spaces
 * and items
 ******************************************/
Campground::Campground(){
	std::string s = "fire.txt";
	spaceName = "Campground";
	msgIntro = "Intro";
	resource.push_back(Item("grass"));
	animal = new Snake();

	ePtr = new Forest(this);
	wPtr = new Lake(this);
	nPtr = new River(this);
	sPtr = new Meadow(this);
}

/*****************************************
 * Function: campground()
 * Description: default destuctor
 ******************************************/
Campground::~Campground(){
}


/*****************************************
 * Function: gather()
 * Description: acquire item; may be attacked by
animal
 ******************************************/
void Campground::gather(Creature* hunter, std::list<Item> &backpack){
	  std::cout << "Cutting " << resource.front().whatami() << "...\n";
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
void Campground::battle(Creature* hunter, std::list<Item> &backpack){
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
	if ( animal->roll(1,2) == 1 
			&& animal->getStrength() > 0 ) {
		hunter->defend(animal, animal->attack(hunter));
	}
	}
}

/*****************************************
 * Function: getDir()
 * Description: return the address
 ******************************************/
Space* Campground::getDir(std::string dir){
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
void Campground::getFile() {
	std::string s = "camp.txt";
	showGraphics(s);
}
