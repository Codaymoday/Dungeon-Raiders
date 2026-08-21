#include "water.h"
water::water()
{
	hp = 5, atk = 0, price = rand() % 10 + 5, def = 2, speedreduction = 0;
	name = "Bottle of Water";
	equipable = false, consumable = true, mageequipable = false;
}
water::~water()
{

}