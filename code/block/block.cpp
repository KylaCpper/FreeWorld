#include "block.h"
#include <iostream>
#include <string>
#include "agk.h"
#include "config.h"
using namespace kyla;

block::block(UINT blockImg,int handness)
{
	
	agk::SetObjectImage(this->Id, blockImg, 0);
	this->Handness = handness;

}

block::~block()
{
}