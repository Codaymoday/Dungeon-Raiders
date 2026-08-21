#include "broadsword.h"
broadsword::broadsword()
{
	hp = 0, atk = 20, price = rand() % 10 + 40, def = 0, speedreduction = 2;
	name = "Broadsword";
	equipable = true, consumable = false, mageequipable = false;
}
broadsword::~broadsword()
{

}