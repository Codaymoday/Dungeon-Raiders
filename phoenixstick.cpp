#include "phoenixstick.h"
phoenixstick::phoenixstick()
{
	hp = -10, atk = 30, price = rand() % 5 + 30, def = 0, speedreduction = 0;
	name = "Stick Infused With a Phoenix Feather";
	equipable = false, consumable = false, mageequipable = true;
}
phoenixstick::~phoenixstick()
{

}