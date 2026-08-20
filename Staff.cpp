#include "Staff.h"
Staff::Staff()
{
	hp = 0, atk = 20, price = rand() % 5 + 30, def = 0, speedreduction = 1;
	name = "Magical Staff";
	equipable = false, consumable = false, mageequipable = true;
}
Staff::~Staff()
{

}