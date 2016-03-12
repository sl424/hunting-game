/***************************************************
 * Program Filename: game.cpp
 * Author: Chewie Lin
 * Date: 12 Mar 2016
 * Description:game class functions 
***************************************************/
#include "game.hpp"

/*****************************************
 * Function: game()
 * Description: default constructor
 * initialise game conditions, space, and hunter
 * and start actions. 
 ******************************************/
Game::Game(){
	mComplete = false;
	setMission();
	max_backsize = 5;
	bool endGame = false;
	time = 20; //10 moves
		system("clear");
		whereami = new Campground();
		whereami->getFile();
		hunter = new Human();

		do{
		//whereami->welcome();
		showStat();
		showAction();
		endGame = askAction();
		} while ( endGame != true );
}

/*****************************************
 * Function: updateProgress()
 * Description: refresh the progress list and check
 * it's complete
 ******************************************/
void Game::updateProgress(){
	progress.clear();
	std::list<Item>::iterator itr;
	for ( itr = mission.begin(); itr != mission.end(); ++itr ){
		std::list<Item>::iterator itr2;
		itr2 = std::find(backpack.begin(),backpack.end(),*itr);
		if ( itr2 != backpack.end() )
			progress.push_back( *itr2 );
	}
	//showList(progress);
	if ( mission.size() == progress.size() )
			mComplete = true;
}

/*****************************************
 * Function: setMission()
 * Description: randomly create the required items
 ******************************************/
void Game::setMission(){
	int nMission = 0;
	std::ifstream ifs;
	std::string sLine;
	ifs.open("item_list.txt", std::ifstream::in);
	do {
		std::getline( ifs, sLine);
		if ( hunter->roll(1,2)==1 ){
			mission.push_back(Item(sLine));
			++nMission;
		}
		if ( ifs.eof() ){
			ifs.clear();
			ifs.seekg(0, std::ios::beg);
		}
	} while ( nMission < 3 );
	ifs.close();
}

/*****************************************
 * Function: showMission()
 * Description: show required items to finish game
 ******************************************/
void Game::showMission(){
	std::cout << "Required ";
	//if ( !mission.empty() ) {
		showList(mission);
	//}
}

/*****************************************
 * Function: showBag()
 * Description: show the items in the bag
 ******************************************/
void Game::showBag(){
	std::cout << "Bag ";
		showList(backpack);
}


/*****************************************
 * Function: askAction()
 * Description: ask for action move 
 * and evaluate game conditions after each move; exit if needed
 ******************************************/
bool Game::askAction(){
	char next;
	do {
	std::cout << "\nWhat to do? ";
	std::cin >> next;
	doAction(next);

	--time;
	if ( hunter->getStrength() <= 0 ){
		std::cout << "\nYou are killed.\n";
		pEnter();
	}
	if ( time == 0 ) {
		std::cout << "You are out of time.\n";
		pEnter();
	}
	checkBagSize();
	updateProgress();
	if ( mComplete == true ) {
		std::cout << "You have acquired all items.\n";
		pEnter();
	}
	} while ( next != 'x' && time != 0 
			&& mComplete == false && hunter->getStrength() > 0);
	gameOver();
	return true;
}


/*****************************************
 * Function: checkBagSize()
 * Description: limit the bag size
 ******************************************/
void Game::checkBagSize(){
	if ( backpack.size() > max_backsize ) {
		std::cout << "Bag is full. Item discarded" << std::endl;
		backpack.pop_back();
	}
}


/*****************************************
 * Function: gameOver()
 * Description: game over message
 ******************************************/
void Game::gameOver(){
	system("clear");
	std::string s = "wolves.txt";
	showGraphics(s);
	if ( hunter->getStrength() <= 0 )
		std::cout << "\nYou are killed. Game Over" << std::endl;
	else if ( time == 0 )
		std::cout << "\nOut of Time. Game Over" << std::endl;
	else if ( mComplete == true )
		std::cout << "\nTask Completed. " << std::endl;
	else 
		std::cout << "\nExiting Game..." << std::endl;
	//if ( next == 'x' )
}


/*****************************************
 * Function: showList()
 * Description: show content of the item list
 ******************************************/
void Game::showList(std::list<Item> listing){
  std::list<Item>::iterator it;
  std::cout << "ITEMS: ";
  for ( it = listing.begin(); it != listing.end(); ++it ) {    
		std::cout << " " << it->whatami();
  }
  std::cout << std::endl;
}


/*****************************************
 * Function: updateList()
 * Description: erase item from the list. not implemented
 ******************************************/
void Game::updateList(std::list<Item> &listing){
  std::list<Item>::iterator it = mission.begin();
	while ( !mission.empty() ) {
		std::list<Item>::iterator it2;
		it2 = std::find(backpack.begin(), backpack.end(), *it);
		if ( it2 != backpack.end() )
			listing.erase(it);
		++it;
  }
}


/*****************************************
 * Function: doAction()
 * Description: call the corresponding functions
 ******************************************/
void Game::doAction(char c){
	if ( c == '1' )
		whereami->find();
	else if ( c == '2' )
		whereami->gather(hunter,backpack);
	else if ( c == '3' ){
		//std::cout << "Attacking..." << std::endl;
		whereami->battle(hunter,backpack);
	}
	else if ( c == 'e' )
		setLocation("east");
	else if ( c == 'w' ) 
		setLocation("west");
	else if ( c == 'n' ) 
		setLocation("north");
	else if ( c == 's' ) 
		setLocation("south");
	else if ( c == '8' )
		showMission();
	else if ( c == '9' )
		showBag();
	else if ( c == '0' )
		discardItem();
	else if ( c == 'x' )
		std::cout << "Exiting Game... " << std::endl;
	else 
		std::cout << "invalid option" << std::endl;
}


/*****************************************
 * Function: discardItem()
 * Description: throw away the last item
 ******************************************/
void Game::discardItem(){
	if ( !backpack.empty() ) {
	std::cout << "Throwing the last item from the bag" << std::endl;
	backpack.pop_back();
	}
	else
		std::cout << "Empty bag" << std::endl;
}


/*****************************************
 * Function: setLocation()
 * Description: change the game location and refresh screen
 ******************************************/
void Game::setLocation(std::string to){
		if ( whereami->getDir(to) == NULL ) {
			std::cout << "Cannot go there" << std::endl;
		}
		else{
			whereami = whereami->getDir(to);
			system("clear");
			whereami->getFile();
			showStat();
			showAction();
		}
}


/*****************************************
 * Function: showAction()
 * Description: menu for possible actions
 ******************************************/
void Game::showAction(){
	std::cout << "\n1: Inspect land \t 2: Gather Resource \t 3: Attack Animal\
		\ne: Go East \t\t w: Go West \t\t n: Go North \t s: Go South \
		\n8: Required Items  \t 9: Check Bag \t\t 0: Discard \t x: Quit " <<std::endl;
}


/*****************************************
 * Function: game()
 * Description: default destructor
 ******************************************/
Game::~Game(){
}


/*****************************************
 * Function: showStat()
 * Description: show status of location, strength and time
 ******************************************/
void Game::showStat(){
	std::cout << "Location: " << whereami->getSpaceName()
		<< "\tStrength: " << hunter->getStrength()
		<< "\tTime Left: " << time << std::endl;
}
