#pragma once
#include "item.h"

class merchant 
{
public:
	merchant();
	virtual ~merchant();

	float getBuyMultiplier();
	void setBuyMultiplier(float multiplier);

	virtual bool buyItemFromPlayer(const item& itemSold);
	virtual void GenerateUI();	
private:

	float buyMultiplier;
};



