/***************************************************
 * Program Filename: state.cpp
 * Author: Chewie Lin
 * Date: 12 Feb 2016
 * Description: main driver functions
 ***************************************************/
#include "state.hpp"

/*****************************************
 * Function: pEnter()
 * Description: press enter to continue
 ******************************************/
void pEnter() {
		std::cin.ignore(125,'\n');
		std::cout << "Press enter to continue: " << std::flush;
		std::cin.ignore(125,'\n');
}
/*****************************************
 * Function: pick()
 * Description: ask user input
 ******************************************/
int pick() {
	int pick;
	do {
	std::cout << "Select a creature: ";
	std::cin >> pick;
	if ( std::cin.fail() || pick < 1 || pick > 5 ) {
		std::cout << "invalid pick" << std::endl;
		std::cin.clear();
		std::cin.ignore(256,'\n');
	}
	} while ( pick < 1 || pick > 5 );
	return pick;
}

/*****************************************
 * Function: showGraphics()
 * Description: 
 ******************************************/
void showGraphics(std::string& s) {
	std::string aline;
	std::ifstream input;
	input.open(s.c_str(), std::ifstream::in);
	if ( input.is_open() ) {
		while ( std::getline (input,aline) )
			std::cout << aline << '\n';
		input.close();
	}
	else std::cout << "error opening file";
}
/*****************************************
 * Function: displayMenu()
 * Description: show the list of creatures
 ******************************************/
bool displayMenu() {
	char a;
	do {
	std::cout << " 0: How to play \n 1: Start Game \n 2: Quit \n";
	std::cout << "Enter input: ";
	std::cin >> a;
	if ( a == '0' )
		showGamePlay();
	if ( a == '1' )
		return true;
	else if ( a == '2' )
		return false;
	} while ( a != '1' && a != '2' );
}

void showGamePlay(){
	std::string s = "gameplay.txt";
	showGraphics(s);
}


