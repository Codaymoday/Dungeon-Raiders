#include "trader.h"
#include <iostream>
using namespace std;

trader::trader()
{
	for (int i = 0; i < maxItemsForTrade; ++i) {
		tradeItems[i] = nullptr;
	}

	tradeItems[0] = new item("placeholder 1", 0.f);
	tradeItems[1] = new item("placeholder 2", 0.f);
	tradeItems[2] = new item("placeholder 3", 0.f);
	tradeItems[3] = new item("placeholder 4", 0.f);
	tradeItems[4] = new item("placeholder 5	", 0.f);
}

trader::~trader()
{
	for (int i = 0; i < maxItemsForTrade; ++i)
	{
		if (tradeItems[i] != nullptr)
		{
			delete tradeItems[i];
			tradeItems[i] = nullptr;
		}
	}
}

void trader::GenerateUI()
{
    cout << "----------------------------------------\n";
    cout << "              TRADER\n";
    cout << "----------------------------------------\n";
    cout << "ALLOHA, wanna trade for some items...?\n";
    cout << "Heres what i have: \n";

    for (int i = 0; i < maxItemsForTrade; ++i)
    {
        if (tradeItems[i] != nullptr)
        {
            cout << "[" << i + 1 << "] "
                << tradeItems[i]->getName()
                << " - Value: $" << tradeItems[i]->getPrice()
                << "\n";
        }
        else
        {
            cout << "[" << i + 1 << "] [Empty]\n";
        }
    }

    cout << "----------------------------------------\n";
    cout << "Select an item to trade.\n";
    cout << "0. Leave\n";
}
