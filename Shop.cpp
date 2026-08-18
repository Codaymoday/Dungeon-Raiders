#include "Shop.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//init shop and randomizes the items that will be sold
Shop::Shop()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < MaxItems; ++i) {
        ShopItems[i] = nullptr;
        ItemValue[i] = 0.0f;
    }

    string itemPool[] = {
        "placeholder 1", "placeholder 2", "placeholder 3",
        "placeholder 4", "placeholder 5", "placeholder 6",
        "placeholder 7", "placeholder 8", "placeholder 9"
    };

    for (int i = 0; i < MaxItems; ++i) {
        string candidateName = "";
        bool isDuplicate = true;

        while (isDuplicate) {
            int randomNameIndex = rand() % 9;
            candidateName = itemPool[randomNameIndex];

            bool foundMatch = false;
            for (int j = 0; j < MaxItems; ++j) {
                if (ShopItems[j] != nullptr) {
                    if (ShopItems[j]->getName() == candidateName) {
                        foundMatch = true;
                    }
                }
            }

            if (!foundMatch) {
                isDuplicate = false;
            }
        }

        float randomPrice = static_cast<float>(rand() % 50 + 10);
        ShopItems[i] = new item(candidateName, randomPrice);
        ItemValue[i] = randomPrice;
    }

    displayUI();
}

// Destructor: Deallocates remaining dynamic memory
Shop::~Shop()
{
    for (int i = 0; i < MaxItems; ++i) {
        if (ShopItems[i] != nullptr) {
            delete ShopItems[i];
            ShopItems[i] = nullptr;
        }
    }
}

//displays current shop UI table
void Shop::displayUI() const
{
    cout << "-------------------------------------------\n";
    cout << "            WELCOME TO THE SHOP            \n";
    cout << "-------------------------------------------\n";
    cout << "SLOT  | ITEM NAME              | BUY PRICE     \n";
    cout << "------|------------------------|---------------\n";

    for (int i = 0; i < MaxItems; ++i) {
        if (ShopItems[i] != nullptr) {
            cout << " [" << i + 1 << "]  | "
                << ShopItems[i]->getName() << "\t\t| $"
                << ItemValue[i] << "\n";
        }
        else {
            cout << " [" << i + 1 << "]  | [ Empty ]          | --\n";
        }
    }
    cout << "-------------------------------------------\n";
}

//when player buys item from slot, frees memory and sets slot to nullptr
bool Shop::buyItem(int slotIndex, float& playerCoin)
{
    int index = slotIndex - 1;

    if (index < 0 || index >= MaxItems) {
        cout << "Invalid slot selection!\n";
        return false;
    }

    if (ShopItems[index] == nullptr) {
        cout << "Slot [" << slotIndex << "] is empty!\n";
        return false;
    }

    if (playerCoin < ItemValue[index]) {
        cout << "Not enough coins! Item costs $" << ItemValue[index]
            << " but you have $" << playerCoin << ".\n";
        return false;
    }

    playerCoin -= ItemValue[index];
    cout << "Bought " << ShopItems[index]->getName() << " for $" << ItemValue[index] << "!\n";

    delete ShopItems[index];
    ShopItems[index] = nullptr;
    ItemValue[index] = 0.0f;

    return true;
}

//pays player 50% value and discards item without adding to ShopItems
float Shop::sellItem(const item& itemToSell)
{
    float payout = itemToSell.getPrice() * 0.5f;

    cout << "Sold " << itemToSell.getName() << " to shop for $" << payout
        << "! The item was processed and discarded.\n";

    return payout;
}

//re-randomizes all items in the shop for 20 Coin
bool Shop::refreshShop(float& playerCoin)
{
    float refreshCost = 20.0f;

    if (playerCoin < refreshCost) {
        cout << "Not enough coins! Refreshing the shop costs $" << refreshCost
            << " but you have $" << playerCoin << ".\n";
        return false;
    }

    playerCoin -= refreshCost;

    //clear existing shop items
    for (int i = 0; i < MaxItems; ++i) {
        if (ShopItems[i] != nullptr) {
            delete ShopItems[i];
            ShopItems[i] = nullptr;
        }
        ItemValue[i] = 0.0f;
    }

    string itemPool[] = {
        "placeholder 1", "placeholder 2", "placeholder 3",
        "placeholder 4", "placeholder 5", "placeholder 6",
        "placeholder 7", "placeholder 8", "placeholder 9"
    };

    //re-populate all slots with unique random items
    for (int i = 0; i < MaxItems; ++i) {
        string candidateName = "";
        bool isDuplicate = true;

        while (isDuplicate) {
            int randomNameIndex = rand() % 9;
            candidateName = itemPool[randomNameIndex];

            bool foundMatch = false;
            for (int j = 0; j < MaxItems; ++j) {
                if (ShopItems[j] != nullptr) {
                    if (ShopItems[j]->getName() == candidateName) {
                        foundMatch = true;
                    }
                }
            }

            if (!foundMatch) {
                isDuplicate = false;
            }
        }

        float randomPrice = static_cast<float>(rand() % 50 + 10);
        ShopItems[i] = new item(candidateName, randomPrice);
        ItemValue[i] = randomPrice;
    }

    cout << "Refreshed the entire shop for $20 coins!\n";
    return true;
}