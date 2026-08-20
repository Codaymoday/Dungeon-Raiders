#include "glassshard.h"
glassshard::glassshard()
{
	hp = -10, atk = 30, price = rand() % 10 + 25, def = -10, speedreduction = 0;
	name = "Glass Shard";
	equipable = true, consumable = false, mageequipable = true;
}
glassshard::~glassshard()
{

}