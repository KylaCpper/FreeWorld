#include "scenes.h"
#include <iostream>
#include "agk.h"
using namespace kyla;
using namespace AGK;

scenes::scenes()
{
	agk::SetClearColor(151, 170, 204); // light blue
	agk::SetSyncRate(60, 0);
	agk::SetScissor(0, 0, 0, 0);
}
scenes::~scenes()
{
}

void scenes::Init()
{

}
