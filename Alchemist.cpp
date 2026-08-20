#include "Alchemist.h"
#include <iostream>
using namespace std;

Alchemist::Alchemist()
{
    for (int i = 0; i < MaxItems; ++i)
    {
        AlchemyItems[i] = nullptr;
        ItemValue[i] = 0.0f;
    }

    AlchemyItems[0] = new item("Potion1", 0.0f);
    AlchemyItems[1] = new item("Potion2", 0.0f);
    AlchemyItems[2] = new item("Potion3", 0.0f);

    for (int i = 0; i < MaxItems; ++i)
    {
        ItemValue[i] = AlchemyItems[i]->getPrice();
    }
}

Alchemist::~Alchemist()
{
    for (int i = 0; i < MaxItems; ++i)
    {
        if (AlchemyItems[i] != nullptr)
        {
            delete AlchemyItems[i];
            AlchemyItems[i] = nullptr;
        }
    }
}

void Alchemist::GenerateUI()
{
    cout << "------------------------------------------------\n";
    cout << "    HELLO THERE PLAYER! WELCOME TO MY SHOP\n";
    cout << "------------------------------------------------\n";
    cout << "SLOT | ITEM NAME                |     PRICE\n";
    cout << "-----|--------------------------|---------------\n";

    for (int i = 0; i < MaxItems; ++i)
    {
        if (AlchemyItems[i] != nullptr)
        {
            cout << " [" << i + 1 << "] | " << AlchemyItems[i]->getName() << "         \t\t| $" << ItemValue[i] << "\n";
        }
        else
        {
            cout << " [" << i + 1 << "] | [ Empty ]                             | --\n";
        }
    }

    cout << "------------------------------------------------\n";
    cout << "Select a potion to buy.\n";
    cout << "0. Leave\n";
}

bool Alchemist::sellItemToPlayer(int slotIndex, float& playerCoin)
{
    int index = slotIndex - 1;

    if (index < 0 || index >= MaxItems)
    {
        cout << "Invalid slot selection!\n";
        return false;
    }

    if (AlchemyItems[index] == nullptr)
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
        << AlchemyItems[index]->getName()
        << " for $" << ItemValue[index] << "!\n";

    delete AlchemyItems[index];
    AlchemyItems[index] = nullptr;
    ItemValue[index] = 0.0f;

    return true;
}
