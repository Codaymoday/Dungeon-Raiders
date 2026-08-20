#include "minihealth.h"
minihealth::minihealth()
{
	hp = 10, atk = 0, price = rand() % 10 + 10, def = 0, speedreduction = 0;
	name = "Minor Health Potion";
	equipable = false, consumable = true, mageequipable = false;
	
}
minihealth::~minihealth()
{

}