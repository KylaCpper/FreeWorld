#include "plane.h"
#include <iostream>
#include "agk.h"
#include "json/json.h"
#include <fstream>  
#include "block.h"
#include "config.h"
using namespace kyla;
using namespace std;

plane::plane()
{
	memset(this, 0, sizeof(plane));
}


plane::~plane()
{

}
void plane::Add(block &Block, float x, float y, float z)
{
	
	float sideLong = Config.BlockSide;
	UINT id = agk::InstanceObject(Block.Id);
	Config.InsertBlockId(id, Block.Id);
	//int a = agk::CreateObjectFromObjectMesh(Plane.planeId,1);
	agk::SetObjectVisible(id, 1);
	agk::SetObjectCollisionMode(id, 1);
	agk::SetObjectPosition(id, x, y , z );
}

void plane::Init(block &Block,int _x,int _y,int _z)
{
	UINT id;
	float sideLong = Config.BlockSide;
	for (int y = 0;y < _y;y++)
	{
		for (float x = 0;x < _x;x++)
		{
			for (float z = 0;z < _z;z++)
			{
				id = agk::InstanceObject(Block.Id);
				Config.InsertBlockId(id, Block.Id);
				//int a = agk::CreateObjectFromObjectMesh(Plane.planeId,1);
				agk::SetObjectVisible(id, 1);
				agk::SetObjectCollisionMode(id, 1);
				agk::SetObjectPosition(id, x * sideLong, y * sideLong, z * sideLong);
				//agk::DrawObject(Plane.planeId);


			}

		}
	}
}
