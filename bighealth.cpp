#include "bighealth.h"
bighealth::bighealth()
{
	hp = 40, atk = 0, price = rand() % 10 + 30, def = 0, speedreduction = 0;
	name = "Big Health Potion";
	equipable = false, consumable = true, mageequipable = false;;
}
bighealth::~bighealth()
{

}