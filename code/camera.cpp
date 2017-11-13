#include "camera.h"
#include <iostream>
#include "agk.h"

using namespace kyla;


camera::camera()
{
	
	this->MainCamera = 1;
	agk::SetCameraPosition(this->MainCamera, 0, 0, 0);
	agk::SetCameraLookAt(this->MainCamera, 0, 0, 0, 0);
	//agk::SetCameraAspect(1, 0.5);
	agk::SetCameraRange(this->MainCamera, 1, 200);
	
}


camera::~camera()
{


}

void camera::CameraSync(int playerId)
{
	//camera sync
	float playerX = agk::GetObjectX(playerId);
	float playerY = agk::GetObjectY(playerId);
	float playerZ = agk::GetObjectZ(playerId);
	agk::SetCameraPosition(this->MainCamera, playerX, playerY, playerZ);
	float getPointerX = (agk::GetPointerX() - 50)/1.5;
	float getPointerY = (agk::GetPointerY() - 50)/1.5;
	agk::Print(agk::GetPointerX());
	agk::Print(agk::GetPointerY());
	agk::RotateObjectLocalY(playerId, getPointerX);
	agk::RotateCameraGlobalY(this->MainCamera, getPointerX);
	agk::RotateCameraLocalX(this->MainCamera, getPointerY);
}
/*
void camera::move()
{

	if (agk::GetRawKeyState(87)) {
		agk::MoveCameraLocalZ(this->mainCamera, 1);
		//w
	}
	if (agk::GetRawKeyState(65)) {
		agk::MoveCameraLocalX(this->mainCamera, -1);
		//a
	}
	if (agk::GetRawKeyState(83)) {
		agk::MoveCameraLocalZ(this->mainCamera, -1);
		//s
	}
	if (agk::GetRawKeyState(68)) {
		agk::MoveCameraLocalX(this->mainCamera, 1);
		//d
	}

	if (agk::GetRawKeyState(32)) {
		agk::MoveCameraLocalY(this->mainCamera, 1);
		//space
	}
	if (agk::GetRawKeyState(16)) {
		agk::MoveCameraLocalY(this->mainCamera, -1);
		//shift
	}


	// get player input


	//agk::SetObjectPosition(this->playerId, this->x, this->y, this->z);
}
*/