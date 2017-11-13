#include "biological.h"
#include <iostream>
#include "AGK.h"
#include "config.h"
using namespace kyla;
using namespace AGK;

biological::biological()
{


}
biological::~biological()
{

}



/*
void biological:: move()
{
	
}

void biological::moveCollision()
{
	float old_x = agk::GetObjectX(this->id);
	float old_y = agk::GetObjectY(this->id);
	float old_z = agk::GetObjectZ(this->id);
	this->move();
	//collision
	float new_x = agk::GetObjectX(this->id);
	float new_y = agk::GetObjectY(this->id);
	float new_z = agk::GetObjectZ(this->id);
	if (agk::ObjectSphereCast(0, old_x, old_y, old_z, new_x, new_y, new_z, Config.playerSide) != 0)
	{
		agk::SetObjectPosition(this->id, agk::GetObjectRayCastSlideX(0), agk::GetObjectRayCastSlideY(0), agk::GetObjectRayCastSlideZ(0));
	}

}
*/