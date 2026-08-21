#include "Brick.h"
Brick::Brick()
{
	hp = 0, atk = 1, price = rand() % 10 + 10, def = 0, speedreduction = 0;
	name = "Brick";
	equipable = false, consumable = true, mageequipable = false;
}
Brick::~Brick()
{

}