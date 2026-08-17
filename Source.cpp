#include <iostream>
#include "Inventory.h"
#include "Item.h"
using namespace std;

int main()
{
	char choice;
	const int numofitems = 72;
	int shownitems = 0;
	Inventory* Backpack = new Inventory;
	Item* newitem = new Item;

	while (true)
	{
		cout << "Open Inventory?(Y/N/I)\n";
		cin >> choice;
		switch(choice)
		{
		case 'Y':
			Backpack->OpenInventory();
			break;
		case 'N':
			cout << "+1 Item" << endl;
			Backpack->storeitem(newitem);
			break;
		case 'I':
			Backpack->selectitem();
			break;
		}
	}
	return 0;
}