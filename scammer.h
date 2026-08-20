#pragma once
#include "merchant.h"
class scammer : public merchant
{
private:
    static const int MaxItems = 3;
    item* ScamItems[MaxItems];
    float ItemValue[MaxItems];

public:
    scammer();
    ~scammer();

    void GenerateUI() override;
    bool buyItemFromPlayer(const item& itemSold) override;
};

