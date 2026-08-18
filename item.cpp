#include "item.h"

// Constructor: Uses assignment inside body instead of initialization list
item::item(std::string n, float p)
{
    name = n;
    price = p;
}

// Destructor: Performs explicit cleanup work
item::~item()
{
    name = "";
    price = 0.0f;
}

std::string item::getName() const
{
    return name;
}

float item::getPrice() const
{
    return price;
}