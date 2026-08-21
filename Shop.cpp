#include "Shop.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread> 
#include <chrono>  
#include <iomanip>

using namespace std;

//helper function to handle character printing
void Shop::animateText(const string& text, int delayMs) const
{
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delayMs));
    }
}

//init shop and randomizes the items that will be sold
Shop::Shop()
{
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
    cout << "------------------------------------------------\n";
    animateText("\033[32m            WELCOME TO THE SHOP            \033[0m\n", 15);
    cout << "------------------------------------------------\n";
    cout << "SLOT | ITEM NAME                |     PRICE     \n";
    cout << "-----|--------------------------|---------------\n";

    for (int i = 0; i < MaxItems; ++i) {
        this_thread::sleep_for(chrono::milliseconds(200)); // delay load animation between slot reveals
        if (ShopItems[i] != nullptr) {
            cout << " [" << i + 1 << "] | " << ShopItems[i]->getName() << "\t\t| \033[92m $ \033[0m" << static_cast<int>(ItemValue[i]) << "\n";
        }
        else {
            cout << " [" << i + 1 << "] | [ Empty ]                | --\n";
        }
    }
    cout << "------------------------------------------------\n";
}

//when player buys item from slot, frees memory and sets slot to nullptr
bool Shop::buyItem(int slotIndex, float& playerCoin)
{
    int index = slotIndex - 1;

    if (index < 0 || index >= MaxItems) {
        animateText("Invalid slot selection!\n");
        return false;
    }

    if (ShopItems[index] == nullptr) {
        animateText("Slot [" + to_string(slotIndex) + "] is empty!\n");
        return false;
    }

    if (playerCoin < ItemValue[index]) {
        string msg = "Not enough coins! Item costs \033[92m $ \033[0m" + to_string(static_cast<int>(ItemValue[index]))
            + " but you have \033[92m $ \033[0m" + to_string(static_cast<int>(playerCoin)) + ".\n";
        animateText(msg);
        return false;
    }

    playerCoin -= ItemValue[index];
    string buyMsg = "Bought " + ShopItems[index]->getName() + " for \033[92m $ \033[0m" + to_string(static_cast<int>(ItemValue[index])) + "!\n";
    animateText(buyMsg);

    delete ShopItems[index];
    ShopItems[index] = nullptr;
    ItemValue[index] = 0.0f;

    displayUI();

    return true;
}

//pays player 50% value and discards item without adding to ShopItems
float Shop::sellItem(const item& itemToSell)
{
    float payout = itemToSell.getPrice() * 0.5f;

    string sellMsg = "Sold " + itemToSell.getName() + " to shop for \033[92m $ \033[0m" + to_string(static_cast<int>(payout))
        + "! The item was processed and discarded.\n";
    animateText(sellMsg);

    return payout;
}

//re-randomizes all items in the shop for 20 Coin
bool Shop::refreshShop(float& playerCoin)
{
    float refreshCost = 20.0f;

    if (playerCoin < refreshCost) {
        string msg = "Not enough coins! Refreshing the shop costs \033[92m $ \033[0m" + to_string(static_cast<int>(refreshCost))
            + " but you have \033[92m $ \033[0m" + to_string(static_cast<int>(playerCoin)) + ".\n";
        animateText(msg);
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

        float randomPrice = static_cast<float>(rand() % 60 + 10);
        ShopItems[i] = new item(candidateName, randomPrice);
        ItemValue[i] = randomPrice;
    }

    animateText("Refreshed the entire shop for \033[92m $ \033[0m 20 coins!\n");
    return true;
}