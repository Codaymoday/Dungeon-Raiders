#include "Ironhelm.h"
Ironhelm::Ironhelm()
{
	hp = 0, atk = 0, price = rand() % 5 + 20, def = 20, speedreduction = 2;
	name = "Iron Helmet";
	equipable = true, consumable = false, mageequipable = true;
}
Ironhelm::~Ironhelm()
{

}