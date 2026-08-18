#include "Inventory.h"
#include <iostream>
using namespace std;

void Inventory::OpenInventory()
{
	for (int y = 0; y < MaxY; y++)
	{
		for (int x = 0; x < MaxX; x++)
		{
            if (x == this->x && y == this->y && IsSelecting) {
                cout << "\033[31m" << backpack[y][x] << " \033[0m";
            }
            else {
                cout << backpack[y][x] << " ";
            }
		}
		cout << endl;
	}
}
Inventory::Inventory()
{
	for (int y = 0; y < MaxY; y++)
	{
		for (int x = 0; x < MaxX; x++)
		{
			if (x == 0 || x == MaxX - 1)
			{
				backpack[y][x] = '|';
			}
            else if (y == 0 || y == MaxY - 1)
            {
                backpack[y][x] = '-';
            }
			else
			{
				backpack[y][x] = '.';
			}
		}
	}
}

int Inventory::storeitem(Item* item)
{
	for (int i = 1; i < 6; i++)
	{
		for (int h = 1; h < 6; h++)
		{
			if (backpack[i][h] == '.')
			{
				backpack[i][h] = 'i';
				true_Backpack[i][h] = item;
				return 0;
			}
		}
	}
}

void Inventory::selectitem()
{
    IsSelecting = true;
    OpenInventory();
    char Movement = '\0';
    int Choice = 0;
    cout << "(1) Select the first item | (2) Move to a different item\n";
    cin >> Choice;
    if (Choice == 1) {
        cout << "\nAre you sure you want to select this item?\n";
        cout << "(1) Select | (2) No\n";
        int areyousure = 0;
        cin >> areyousure;
        if (areyousure == 1)
        {
            promptequip();
            IsSelecting = false;
        }
        else
        {
            selectitem();
        }
    }
    else {
        cout << "\nWhere would you like to move?\n";
        cout << "W, A, S or D. Press K to select.\n";

        while (true) {
            cin >> Movement;
            while (Movement != 'W' && Movement != 'A' && Movement != 'S' && Movement != 'D' && Movement != 'K') {
                cout << "Please input valid movement.\n";
            }
            if (UpdateLocation(Movement)) {
                OpenInventory();
                if (Movement == 'K') {
                    IsSelecting = false;
                    break;
                }
            }
            else {
                cout << "Unable to move there. Please try again.\n";
            }
        }
    }
}

bool Inventory::UpdateLocation(char where) {
    char Location = '\0';
    int locX = x, locY = y;
    switch (where) {
    case 'W':
        locY -= 1;
        break;
    case 'A':
        locX -= 1;
        break;
    case 'S':
        locY += 1;
        break;
    case 'D':
        locX += 1;
        break;
    case 'K':
        return true;
    default:
        return false;
    }
    if (locX >= MaxX || locX < 0 ||
        locY < 0 || locY >= MaxY) {
        return false;
    }
    else {
        Location = backpack[locY][locX];

        if (Location != 'G' && Location != '#') {
            y = locY; x = locX;
            return true;
        }
        else {
            return false;
        }
    }

}

void Inventory::promptequip()
{
    int select = 0;
    cout << "Would you like to inspect or equip this weapon?\n";
    cout << "(1) Inspect | (2) Equip\n";
    cin >> select;
    if (select == 1)
    {
        cout << "You inspected the item\n";
    }
    else if (select == 2)
    {
        cout << "You Equipped the item\n";
        OpenInventory();
    }
    else
    {
        cout << "Please select a proper option\n";
    }
}
