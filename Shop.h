#pragma once
#include "item.h"

class Shop {
private:
    static const int MaxItems = 5;
    item* ShopItems[MaxItems];
    float ItemValue[MaxItems];

public:
    Shop();
    ~Shop();

    void displayUI() const;
    bool buyItem(int slotIndex, float& playerCoin);
    float sellItem(const item& itemToSell);
    bool refreshShop(float& playerCoin);
};