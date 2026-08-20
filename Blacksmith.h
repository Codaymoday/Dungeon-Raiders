#pragma once
#include "merchant.h"
class Blacksmith : public merchant
{
private:
    static const int MaxItems = 3;
    item* BlacksmithItems[MaxItems];
    float ItemValue[MaxItems];

public:
    Blacksmith();
    ~Blacksmith();

    void GenerateUI() override;
    bool sellItemToPlayer(int slotIndex, float& playerCoin);
};

