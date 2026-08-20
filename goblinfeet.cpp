#include "goblinfeet.h"
goblinfeet::goblinfeet()
{
	hp = 0, atk = 0, price = rand() % 5 + 15, def = 0, speedreduction = 0;
	name = "Goblin Feet";
	equipable = false, consumable = false, mageequipable = false;
}
goblinfeet::~goblinfeet()
{

}