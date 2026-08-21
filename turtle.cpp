#include "turtle.h"
turtle::turtle()
{
	hp = 20, atk = -5, price = rand() % 10 + 20, def = 30, speedreduction = 5;
	name = "Turtle Shell Necklace";
	equipable = true, consumable = false, mageequipable = true;
}
turtle::~turtle()
{

}