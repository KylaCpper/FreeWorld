#include "shortCutBar.h"
#include <iostream>
#include "overall.h"
using namespace kyla;
UINT shortCutBar::SelectId = 1;
UINT shortCutBar::SelectItemId = 0;

shortCutBar::shortCutBar():NextSpaceId(this->SpaceTotal * 2 + this->SpaceId + 1)
{
	UINT hand_bag= agk::LoadSubImage(Config.GetGuiImg("Widgets"), "hand_bag");
	UINT hand_select = agk::LoadSubImage(Config.GetGuiImg("Widgets"), "hand_select");
	UINT hand_bag_bg=agk::CreateSprite(hand_bag);
	agk::SetSpriteSize(hand_bag_bg, this->UiWidth, this->UiHeight);
	agk::SetSpriteVisible(hand_bag_bg, 0);
	//agk::SetSpritePosition(this->HandBagBg,(100 - this->HandWidth) / 2, this->HandSelectOffset_Y);
	agk::SetSpriteDepth(hand_bag_bg, 10);
	//
	agk::CreateSprite(this->SelectId_Gui,hand_select);
	agk::SetSpriteSize(this->SelectId_Gui, this->UiWidth,this->UiHeight);
	agk::SetSpritePosition(this->SelectId_Gui, this->ItemOffset_X, this->ItemOffset_Y);
	agk::SetSpriteDepth(this->SelectId_Gui,9);
	//gui hand item
	UINT gui_hand_item = agk::CreateSprite(0);
	agk::SetSpriteSize(gui_hand_item, this->ItemWidth, this->ItemHeight);
	agk::SetSpriteVisible(gui_hand_item, 0);
	agk::SetSpriteDepth(gui_hand_item, 8);
	int offset = (this->UiHeight - this->ItemHeight) / 2;
	for (int i = 0;i < this->Column;i++)
	{
		agk::CloneSprite(i+1, hand_bag_bg);
		agk::SetSpritePosition(i+1, this->ItemOffset_X + i*this->Offset, this->ItemOffset_Y);
		agk::SetSpriteVisible(i+1, 1);
		//
		agk::CloneSprite(i+1+ this->SpaceTotal, gui_hand_item);
		agk::SetSpritePosition(i+1+ this->SpaceTotal, this->ItemOffset_X + i*this->Offset + offset, offset + this->ItemOffset_Y);
		
	}





}
shortCutBar::~shortCutBar()
{

}
//key  改变选中  point to piont
void shortCutBar::ChangSelect(UINT num)
{
	agk::SetSpritePosition(SelectId_Gui, ItemOffset_X + (num-1)*Offset, ItemOffset_Y);
	SelectId = num;
	ChangeSelectItemId();
}
//滑轮改变选中
void shortCutBar::ChangSelectWhell(int num)
{
	//<1 =9
	SelectId -= num;
	if (SelectId < SpaceId)
	{
		SelectId = SpaceTotal;
	}
	//>9 =1
	if (SelectId > SpaceTotal)
	{
		SelectId = SpaceId;
	}
	ChangeSelectItemId();

	agk::SetSpritePosition(SelectId_Gui, ItemOffset_X + (SelectId - 1)*Offset, ItemOffset_Y);
	
}
//9格子 改变 物品 
void shortCutBar::ChangeSpace(UINT spaceId, UINT itemId)
{
	spaceId += SpaceTotal;
	if (itemId)
	{
		agk::SetSpriteImage(spaceId, itemId);
		agk::SetSpriteVisible(spaceId, 1);
	}
	else
	{
		agk::SetSpriteImage(spaceId, 0);
		agk::SetSpriteVisible(spaceId, 0);
	}
	
}

void shortCutBar::ChangeSelectItemId()
{
	SelectItemId = agk::GetSpriteImageID(SelectId + 9);

}




