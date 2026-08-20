#include "Ironchest.h"
Ironchest::Ironchest()
{
	hp = 0, atk = 0, price = rand() % 5 + 30, def = 40, speedreduction = 3;
	name = "Iron Chestplate";
	equipable = true, consumable = false, mageequipable = true;
}
Ironchest::~Ironchest()
{

}