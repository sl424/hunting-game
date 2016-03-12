#include "game.hpp"
#include <iostream>
#include "state.hpp"
#include <string>
#include <cstdlib>

int main() {

	bool c;
	srand(time(0));
	system("clear");
	std::string s = "mountain.txt";
	showGraphics(s);
	c = displayMenu();
	if ( c == true ) 
		Game();
	return 0;
}
