#pragma once
#include "merchant.h"
class Alchemist : public merchant
{
private:
    static const int MaxItems = 3;
    item* AlchemyItems[MaxItems];
    float ItemValue[MaxItems];

public:
    Alchemist();
    ~Alchemist();

    void GenerateUI() override;
    bool sellItemToPlayer(int slotIndex, float& playerCoin);
};

