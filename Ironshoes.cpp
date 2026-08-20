#include "Ironshoes.h"
Ironshoes::Ironshoes()
{
	hp = 0, atk = 0, price = rand() % 10 + 10, def = 10, speedreduction = 1;
	name = "Iron Boots";
	equipable = true, consumable = false, mageequipable = true;
}
Ironshoes::~Ironshoes()
{

}