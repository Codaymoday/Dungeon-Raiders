#include "Blacksmith.h"
#include <iostream>
#include <string>
using namespace std;

Blacksmith::Blacksmith()
{
    for (int i = 0; i < MaxItems; ++i)
    {
        BlacksmithItems[i] = nullptr;
        ItemValue[i] = 0.0f;
    }

    BlacksmithItems[0] = new item("placeholder1", 0.f);
    BlacksmithItems[1] = new item("placeholder2", 0.f);
    BlacksmithItems[2] = new item("placeholder3", 0.f);

    for (int i = 0; i < MaxItems; ++i)
    {
        ItemValue[i] = BlacksmithItems[i]->getPrice();
    }
}

Blacksmith::~Blacksmith()
{
    for (int i = 0; i < MaxItems; ++i)
    {
        if (BlacksmithItems[i] != nullptr)
        {
            delete BlacksmithItems[i];
            BlacksmithItems[i] = nullptr;
        }
    }
}

void Blacksmith::GenerateUI()
{
    cout << "------------------------------------------------\n";
    cout << "         HELLO WELCOME TO MY SHOP!\n";
    cout << "------------------------------------------------\n";
    cout << "SLOT | ITEM NAME                |     PRICE\n";
    cout << "-----|--------------------------|---------------\n";

    for (int i = 0; i < MaxItems; ++i)
    {
        if (BlacksmithItems[i] != nullptr)
        {
            cout << " [" << i + 1 << "] | "
                << BlacksmithItems[i]->getName()
                << "\t\t| $"
                << ItemValue[i] << "\n";
        }
        else
        {
            cout << " [" << i + 1 << "] | [ Empty ]                | --\n";
        }
    }

    cout << "------------------------------------------------\n";
    cout << "Select a weapon or armour to buy.\n";
    cout << "0. Leave\n";
}

bool Blacksmith::sellItemToPlayer(int slotIndex, float& playerCoin)
{
    int index = slotIndex - 1;

    if (index < 0 || index >= MaxItems)
    {
        cout << "Invalid slot selection!\n";
        return false;
    }

    if (BlacksmithItems[index] == nullptr)
    {
        cout << "That slot is empty!\n";
        return false;
    }

    if (playerCoin < ItemValue[index])
    {
        cout << "Not enough coins!\n";
        return false;
    }

    playerCoin -= ItemValue[index];

    cout << "Bought "
        << BlacksmithItems[index]->getName()
        << " for $" << ItemValue[index] << "!\n";

    delete BlacksmithItems[index];
    BlacksmithItems[index] = nullptr;
    ItemValue[index] = 0.0f;

    return true;
}
