#pragma once
#include "merchant.h"

class trader : public merchant
{
public:
	trader();
	~trader();


	void GenerateUI() override;

private:
	static const int maxItemsForTrade = 5;
	item* tradeItems[maxItemsForTrade];
};

