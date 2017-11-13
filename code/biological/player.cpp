#include "player.h"
#include <iostream>
#include "AGK.h"
#include "config.h"
using namespace kyla;
using namespace AGK;

player::player()
{
	//memset(this, 0, sizeof(player));
	//this->be = agk::LoadImage("assets/images/other/destroy_stage_4.png");


	float playerSide = Config.PlayerSide;
	this->Id = agk::CreateObjectBox(playerSide, playerSide, playerSide);
	agk::SetObjectPosition(this->Id, 0, 10, 0);
	agk::SetObjectColor(this->Id, 0, 255, 0, 100);
	agk::SetObjectCollisionMode(this->Id, 0);

}
player::~player()
{

}


void player:: Move() 
{
	//agk::MoveObjectLocalY(this->playerId, -this->downSpeed);
	if (agk::GetRawKeyState(87)) {
		agk::MoveObjectLocalZ(this->Id, Config.MoveSpeed);
		//w
	}
	if (agk::GetRawKeyState(65)) {
		agk::MoveObjectLocalX(this->Id, -Config.MoveSpeed);
		//a
	}
	if (agk::GetRawKeyState(83)) {
		agk::MoveObjectLocalZ(this->Id, -Config.MoveSpeed);
		//s
	}
	if (agk::GetRawKeyState(68)) {
		agk::MoveObjectLocalX(this->Id, Config.MoveSpeed);
		//d
	}

	if (agk::GetRawKeyPressed(32)) {
		agk::MoveObjectLocalY(this->Id, Config.JumpSpeed);
		//space
	}
	if (agk::GetRawKeyState(16)) {
		agk::MoveObjectLocalY(this->Id, -Config.DownSpeed);
		//shift
	}
	
	// get player input


	//agk::SetObjectPosition(this->playerId, this->x, this->y, this->z);
}


void player::MoveCollision()
{
	float old_x = agk::GetObjectX(this->Id);
	float old_y = agk::GetObjectY(this->Id);
	float old_z = agk::GetObjectZ(this->Id);
	this->Move();
	//collision
	float new_x = agk::GetObjectX(this->Id);
	float new_y = agk::GetObjectY(this->Id);
	float new_z = agk::GetObjectZ(this->Id);
	if (agk::ObjectSphereCast(0, old_x, old_y, old_z, new_x, new_y, new_z, Config.PlayerSide) != 0)
	{
		agk::SetObjectPosition(this->Id, agk::GetObjectRayCastSlideX(0), agk::GetObjectRayCastSlideY(0), agk::GetObjectRayCastSlideZ(0));
	}
}

void player::HandItem()
{

}