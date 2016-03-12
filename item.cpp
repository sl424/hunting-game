/***************************************************
 * Program Filename: item.cpp
 * Author: Chewie Lin
 * Date: 12 Mar 2016
 * Description:item class functions 
***************************************************/
#include "item.hpp"

/*****************************************
 * Function: item()
 * Description: create the item with name
 ******************************************/
Item::Item(std::string s){
	name = s;
}


/*****************************************
 * Function: item()
 * Description: default destructor
 ******************************************/
Item::~Item(){
}


/*****************************************
 * Function: whatami()
 * Description: return item name
 ******************************************/
std::string Item::whatami() {
	return name;
}


/*****************************************
 * Function: operator==()
 * Description: overload == 
 ******************************************/
const bool Item::operator==( const Item right ) {
	if ( name == right.name )
		return true;
	else 
		return false;
}


/*****************************************
 * Function: operator!=()
 * Description: overload !=
 ******************************************/
const bool Item::operator!=( const Item right ) {
	if ( name != right.name )
		return true;
	else 
		return false;
}

