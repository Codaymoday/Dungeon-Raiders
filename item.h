#pragma once
#include <string>

class item {
private:
    std::string name;
    float price;

public:
    item(std::string n = "Generic Item", float p = 20.0f);
    ~item();

    std::string getName() const;
    float getPrice() const;
};