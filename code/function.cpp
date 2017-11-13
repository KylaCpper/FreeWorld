#include "function.h"
#include <iostream>
#include "agk.h"
using namespace kyla;

void function::BreakCheckBlock(UINT &time, UINT mousePointer)
{
	if (time != 0)
	{
		agk::SetObjectImage(mousePointer, 0, 1);
	}
	time = 0;

}
void function::DestroyStages_Init(UINT *destroyStages)
{
	destroyStages[0] = agk::LoadImage("assets/images/other/destroy_stage_none.png");
	for (int i = 1;i < 10;i++)
	{
		char be[100];
		sprintf(be, "assets/images/other/destroy_stage_%d.png", i - 1);
		destroyStages[i] = agk::LoadImage(be);
	}
}

