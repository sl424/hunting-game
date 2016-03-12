/***************************************************
 * Program Filename: space.cpp
 * Author: Chewie Lin
 * Date: 12 Mar 2016
 * Description:space class functions 
***************************************************/
#include "space.hpp"
#include "item.hpp"
#include <list>

/*****************************************
 * Function: space()
 * Description: default constructor abstract class
 ******************************************/
Space::Space() {
}

/*****************************************
 * Function: space()
 * Description: default destructor
 ******************************************/
Space::~Space(){
}

/*****************************************
 * Function: find()
 * Description: list animal and items
 ******************************************/
void Space::find() {
	showAnimal();
	//if ( !resource.empty() )
		showResource();
}

/*****************************************
 * Function: welcome()
 * Description: a welcome msg
 ******************************************/
void Space::welcome(){
	std::cout << msgIntro << std::endl;
}

/*****************************************
 * Function: getSpaceName()
 * Description: return location name
 ******************************************/
std::string Space::getSpaceName(){
	return spaceName;
}

/*****************************************
 * Function: showAnimal()
 * Description: list wild animal
 ******************************************/
void Space::showAnimal() {
	std::cout << "Wild animal: ";
	if ( animal != NULL )
		std::cout << animal->getName(); 
	std::cout << std::endl;
}

/*****************************************
 * Function: showResource()
 * Description: show items
 ******************************************/
void Space::showResource(){
	std::list<Item>::iterator it;
	std::cout << "Resources: ";
	for ( it = resource.begin(); it != resource.end(); ++it ) {
		std::cout << " " << it->whatami();
	}
	std::cout << std::endl;
}

/*****************************************
 * Function: getAnimal()
 * Description: return pointer to the animal
 ******************************************/
Creature* Space::getAnimal(){
	return animal;
}
