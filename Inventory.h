#pragma once
#include "Item.h"
class Inventory
{
public:
	void OpenInventory();
	Inventory();
	void setpos(int posx, int posy);
	int getx();
	int gety();
	int storeitem(Item* item);
	void selectitem();
	void equipitem();
	bool UpdateLocation(char where);
	void promptequip();

private:
	static const int MAX_SPACE = 49, MaxX = 7, MaxY = 7;
	bool IsSelecting{};
	int numofitems = 0;
	int x = 1, y = 1;
	char backpack[MaxY][MaxX] = {};
	Item* true_Backpack[MaxY][MaxX] = {};
};

