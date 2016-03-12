/*****************************************
* Program Filename: item.hpp
* Author: Chewie Lin
* Date: 12 Mar 2016
* Description: item class prototypes
*****************************************/
#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>

class Item {
	protected:
		std::string name;
	public:
		Item(std::string);
		~Item();
		std::string whatami();
		const bool operator==(const Item);
		const bool operator!=(const Item);
};

#endif
