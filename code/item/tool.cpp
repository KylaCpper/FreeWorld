#include "tool.h"
#include <iostream>
using namespace kyla;


tool::tool(UINT id)
{
	itemBase::Id = id;
}
tool::~tool()
{

}

void tool::RightFunction()
{
	agk::Print("right tool");
}