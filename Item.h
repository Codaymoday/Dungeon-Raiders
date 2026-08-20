#pragma once
#include <iostream>
#include <string>
using namespace std;
class Item
{
public:
	int hp = 0, atk = 0, def = 0, price = 0, speedreduction = 0;
	string name = "name";
	bool equipable = false, consumable = false, mageequipable = false;
    Item();
};

