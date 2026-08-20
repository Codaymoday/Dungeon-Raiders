#include "scammer.h"
#include <iostream>
#include <string>
using namespace std;

scammer::scammer()
{
    setBuyMultiplier(0.3f);

    for (int i = 0; i < MaxItems; ++i)
    {
        ScamItems[i] = nullptr;
        ItemValue[i] = 0.0f;
    }

    ScamItems[0] = new item("placeholder1", 0.0f);
    ScamItems[1] = new item("placeholder2", 0.0f);
    ScamItems[2] = new item("placeholder3", 0.0f);

    for (int i = 0; i < MaxItems; ++i)
    {
        int multiply = rand() % 3 + 2;
        ItemValue[i] = ScamItems[i]->getPrice() * multiply;
    }
}

scammer::~scammer()
{
    for (int i = 0; i < MaxItems; ++i)
    {
        if (ScamItems[i] != nullptr)
        {
            delete ScamItems[i];
            ScamItems[i] = nullptr;
        }
    }
}

void scammer::GenerateUI()
{
    cout << "------------------------------------------------\n";
    cout << "              WELCOME TO THE SHOP, hehe\n";
    cout << "------------------------------------------------\n";
    cout << "SLOT | ITEM NAME                |     PRICE\n";
    cout << "-----|--------------------------|---------------\n";

    for (int i = 0; i < MaxItems; ++i)
    {
        if (ScamItems[i] != nullptr)
        {
            cout << " [" << i + 1 << "] | "
                << ScamItems[i]->getName()
                << "\t\t| $"
                << ItemValue[i] << "\n";
        }
        else
        {
            cout << " [" << i + 1 << "] | [ Empty ]                | --\n";
        }
    }

    cout << "------------------------------------------------\n";
    cout << "0. Leave\n";
}

bool scammer::buyItemFromPlayer(const item & itemSold)
{
    float payout = itemSold.getPrice() * getBuyMultiplier();

    cout << "The Scammer offers you only $"
        << payout << " for "
        << itemSold.getName() << "!\n";

    return true;
}
