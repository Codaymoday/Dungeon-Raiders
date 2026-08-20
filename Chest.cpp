#include "Chest.h"
#include <iostream>
#include "Item.h"
using namespace std;


Chest::Chest() {}

void Chest::OpenChest() {
	char choices;
	int AmtOfItems = (rand() % 14) +3 ;

	while (true) {
		cout << "You found a chest!\n";
		cout << "Open it? (Y/N)\n";
		cin >> choices;

			if (choices == 'Y') {
				cout << "You opened the chest!\n";
				cout << "You obtained " << AmtOfItems << " items!\n";

				for (int i = 0; i < AmtOfItems; i++) {
					Item* newItem = new Item("Item", i);
					cout << " -> Picked up item #" << (i + 1) << "\n";



				}
			}

			else if (choices == 'N') {
				cout << "You left the chest alone...\n";
			}
	}
}
