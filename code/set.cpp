#include "set.h"
#include <iostream>
#include "agk.h"
using namespace kyla;
using namespace AGK;

set::set()
{
	agk::SetVSync(0);
	agk::SetFogMode(1);
	agk::ClearPointLights();
}
set::~set()
{

}

void set::init()
{

}
