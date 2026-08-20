#include "Mystery.h"
Mystery::Mystery()
{
	hp = rand() % 50 - 20, atk = rand() % 50 - 20, price = rand() % 50, def = rand() % 50 - 20, speedreduction = rand() % 5;
	name = "Mystery Potion";
	equipable = false, consumable = true, mageequipable = false;
}
Mystery::~Mystery()
{

}