#include "blockBase.h"
#include <iostream>
#include <string>
#include "agk.h"
#include "config.h"
using namespace kyla;
blockBase::blockBase()
{
    float sideLong = Config.BlockSide;
	this->Id = agk::CreateObjectBox(sideLong, sideLong, sideLong);
	//agk::SetObjectColorEmissive(this->Id,0,0,0);
	agk::SetObjectLightMode(this->Id, 0);
	agk::SetObjectTransparency(this->Id, 0);
	//image = agk::LoadImage("assets/images/other/destroy_stage_0.png");
	//agk::SetObjectImage(this->Id, image, 1);
	//agk::SetObjectPosition(this->dirt, 0, 5, 0);
	agk::SetObjectVisible(this->Id, 0);
	agk::SetObjectCollisionMode(this->Id, 0);
}

blockBase::~blockBase()
{
}

