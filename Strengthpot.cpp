#include "Strengthpot.h"
Strengthpot::Strengthpot()
{
	hp = 0, atk = 15, price = rand() % 10 + 25, def = 0, speedreduction = 0;
	name = "Iron Helmet";
	equipable = false, consumable = true, mageequipable = false;
}
Strengthpot::~Strengthpot()
{

}