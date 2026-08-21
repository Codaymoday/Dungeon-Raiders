#include "Defpot.h"
Defpot::Defpot()
{
	hp = 5, atk = 0, price = rand() % 10 + 25, def = 10, speedreduction = 0;
	name = "Defence Potion";
	equipable = false, consumable = true, mageequipable = false;
}