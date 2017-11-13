#include "item.h"
#include <iostream>
#include "config.h"
#include "overall.h"
using namespace kyla;


item::item(UINT itemId)
{
	this->ItemId = itemId;
	this->Id = agk::CreateObjectPlane(1, 1);
	agk::SetObjectImage(this->Id, itemId, 0);
	//agk::SetObjectPosition(cc, 10, 10, 10);
	agk::SetObjectLightMode(this->Id, 0);
	agk::SetObjectTransparency(this->Id, 1);
	agk::SetObjectCollisionMode(this->Id, 0);
	//this->HandItem();
}
item::item()
{

}
item::~item()
{

}

void item::RightFunction()
{
	agk::Print("right item");
}




