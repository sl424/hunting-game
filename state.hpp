/*****************************************
* Program Filename: state.hpp
* Author: Chewie Lin
* Date: 12 Feb 2016
* Description: main drive function headers
*****************************************/
#include "creature.hpp"
#include <string>
#include <fstream>
#include <iostream>
#ifndef STATE_HPP
#define STATE_HPP

void showGraphics(std::string& s);
void showGamePlay();
int pick();
bool displayMenu();
void pEnter();

#endif
