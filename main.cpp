#include "Shop.h"
#include <iostream>

using namespace std;

int main()
{
    Shop myShop;
    float playerCoins = 100.0f;
    int choice = 0;

    item magicRing("Magic Ring", 80.0f);
    item staminaHerb("Stamina Herb", 12.0f);

    while (choice != 4)
    {
        cout << "\nPlayer Coins: $" << playerCoins << "\n";
        cout << "1. Buy Item from Shop\n";
        cout << "2. Sell Item to Shop\n";
        cout << "3. Randomize Shop ($20 Coins)\n";
        cout << "4. Exit\n";
        cout << "Select Choice (1-4): ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a number.\n";
        }
        else {
            cout << "\n";

            switch (choice)
            {
            case 1: {
                int slot = 0;
                cout << "Enter slot to buy (1-5): ";
                cin >> slot;
                myShop.buyItem(slot, playerCoins);
                break;
            }
            case 2: {
                cout << "Select item to sell:\n";
                cout << "1. " << magicRing.getName() << " (Value: $" << magicRing.getPrice() << ")\n";
                cout << "2. " << staminaHerb.getName() << " (Value: $" << staminaHerb.getPrice() << ")\n";
                cout << "Choice: ";
                int itemChoice = 0;
                cin >> itemChoice;

                if (itemChoice == 1) {
                    playerCoins += myShop.sellItem(magicRing);
                }
                else if (itemChoice == 2) {
                    playerCoins += myShop.sellItem(staminaHerb);
                }
                else {
                    cout << "Invalid item selection!\n";
                }
                break;
            }
            case 3:
                myShop.randItem(playerCoins);
                break;

            case 4:
                cout << "Exiting shop loop.\n";
                break;

            default:
                cout << "Invalid selection!\n";
                break;
            }

            if (choice != 4) {
                cout << "\n";
                myShop.displayUI();
            }
        }
    }

    return 0;
}