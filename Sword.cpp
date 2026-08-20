#include "Sword.h"
Sword::Sword()
{
	hp = 0, atk = 10, price = rand() % 10 + 20, def = 0, speedreduction = 1;
	name = "Sword";
	equipable = true, consumable = false, mageequipable = false;
}
Sword::~Sword()
{

}