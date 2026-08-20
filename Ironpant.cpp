#include "Ironpant.h"
Ironpant::Ironpant()
{
	hp = 0, atk = 0, price = rand() % 10 + 25, def = 30, speedreduction = 2;
	name = "Iron Leggings";
	equipable = true, consumable = false, mageequipable = true;
}
Ironpant::~Ironpant()
{

}