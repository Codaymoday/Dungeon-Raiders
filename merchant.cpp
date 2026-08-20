#include "merchant.h"
#include <iostream>
#include <string>
using namespace std;

merchant::merchant() //init merchant stuff
{
	buyMultiplier = 0.7f;
}

merchant::~merchant()
{}

float merchant::getBuyMultiplier()
{
	return buyMultiplier;
}

void merchant::setBuyMultiplier(float multiplier)
{
	buyMultiplier = multiplier;
}

bool merchant::buyItemFromPlayer(const item & itemSold)
{
	float payout = itemSold.getPrice() * buyMultiplier;

	cout << "Player Sold " << itemSold.getName() << "for \033[92m$\033[0m" << payout << endl;
	
	return true;
}

void merchant::GenerateUI()
{
	cout << "====================\n";
	cout << "        Merchant\n";
	cout << "====================\n";
	cout << "Hello there player! Looking to sell anything?\n";
	cout << "(1). Sell Items\n";
	cout << "(2). Leave :(\n";
}

