#include "bag.h"
#include <iostream>
#include "shortCutBar.h"
using namespace kyla;
using namespace std;
using namespace Json;


bag::bag(UINT next)
{
	gui::UiWidth = 57;
	gui::UiHeight = 33;
	gui::ItemWidth = 5;
	gui::ItemHeight = 5;
	gui::ItemOffset_X = 23;
	gui::ItemOffset_Y = 35;
	gui::Offset = 6;
	gui::Row = 4;
	gui::Column = 9;
	gui::SpaceId = next;
	gui::SpaceTotal= gui::Row*gui::Column;
	gui::NextSpaceId = gui::SpaceTotal * 3 + gui::SpaceId;

	UINT img = agk::LoadSubImage(Config.GetGuiImg("Background"), "bag");
	gui::Id = agk::CreateSprite(img);
	agk::SetSpriteDepth(gui::Id, gui::Depth);
	agk::SetSpriteSize(gui::Id, gui::UiWidth, gui::UiHeight);
	agk::SetSpritePosition(gui::Id, (100 - gui::UiWidth) / 2, (100 - gui::UiHeight) / 2);
	agk::SetSpriteVisible(gui::Id, 0);
	//gui space
	UINT gui_down = agk::LoadSubImage(Config.GetGuiImg("Stats_Icons"), "down");
	UINT gui_space = agk::CreateSprite(gui_down);
	//agk::SetSpriteColor(item_bg, 255, 255, 255, 100);
	agk::SetSpriteSize(gui_space, gui::ItemWidth, gui::ItemHeight);
	agk::SetSpriteVisible(gui_space, 0);
	agk::SetSpriteDepth(gui_space, 9);
	//gui item
	UINT gui_space_item = agk::CreateSprite(0);
	//agk::SetSpriteColor(gui_space_item, 255, 255, 255, 100);
	agk::SetSpriteSize(gui_space_item, gui::ItemWidth, gui::ItemHeight);
	agk::SetSpriteVisible(gui_space_item, 0);
	agk::SetSpriteDepth(gui_space_item, 8);
	//gui space bg
	UINT gui_space_select = agk::CreateSprite(0);
	agk::SetSpriteColor(gui_space_select, 255, 255, 255, 100);
	agk::SetSpriteSize(gui_space_select, gui::ItemWidth, gui::ItemHeight);
	agk::SetSpriteVisible(gui_space_select, 0);
	agk::SetSpriteDepth(gui_space_select, 7);



	for (UINT i = 0;i < gui::Row;i++)
	{
		int offset_be = 0;
		if (i == gui::Row-1)
			offset_be = 1;
		for (UINT j = 0;j < gui::Column;j++)
		{
			UINT spaceId = gui::SpaceId + j + i * gui::Column;
			agk::CloneSprite(spaceId, gui_space);
			agk::SetSpritePosition(spaceId, gui::ItemOffset_X + j*gui::Offset, gui::ItemOffset_Y + (i+ offset_be)*gui::Offset);
			agk::SetSpriteCategoryBit(spaceId,2,1);
			//agk::SetSpriteColor(pickaxe, 255, 255, 255, 255);
			
			UINT spaceId_ = gui::SpaceTotal + gui::SpaceId + j + i * gui::Column;
			agk::CloneSprite(spaceId_, gui_space_item);
			agk::SetSpritePosition(spaceId_, gui::ItemOffset_X + j*gui::Offset, gui::ItemOffset_Y + (i + offset_be)*gui::Offset);

			UINT spaceId__ = gui::SpaceTotal*2+ gui::SpaceId + j + i * gui::Column;
			agk::CloneSprite(spaceId__, gui_space_select);
			agk::SetSpritePosition(spaceId__, gui::ItemOffset_X + j*gui::Offset, gui::ItemOffset_Y + (i + offset_be)*gui::Offset);

		

		}
	}
}
bag::~bag()
{

}

void bag::Close() 
{
	agk::SetSpriteVisible(gui::Id, 0);
	for (UINT i= gui::SpaceId;i < gui::SpaceId + gui::SpaceTotal*3;i++)
		agk::SetSpriteVisible(i, 0);
	gui::ShortCulBar_Updata();
	

}

void bag::Open() 
{
	agk::SetSpriteVisible(gui::Id, 1);
	for (UINT i = gui::SpaceId;i < gui::SpaceId + gui::SpaceTotal * 2;i++)
	{
		if(agk::GetSpriteImageID(i))
			agk::SetSpriteVisible(i, 1);
	}
	gui::ShortCulBar_Updata();
		
}
void bag::Display()
{
	if (gui::Visible) 
		this->Open();
	else
		this->Close();
	
}
void bag::Event()
{
	//cached select 0
	agk::SetSpriteVisible(gui::SelectId_Gui, 0);
	//get new select 1
	float mx = agk::GetPointerX();
	float my = agk::GetPointerY();
	gui::SelectId=agk::GetSpriteHitCategory(2,mx,my);
	
	//clicked
	if (gui::Select_Click)
	{
		this->MoveClick(mx, my);
	}
	if (gui::SelectId)
	{

		//spacetotal-1 == space bg
		gui::SelectId_Gui = gui::SelectId + gui::SpaceTotal * 2;
		agk::SetSpriteVisible(gui::SelectId_Gui, 1);
		//click
		if (agk::GetPointerReleased())
		{
			UINT clickId= gui::SelectId + gui::SpaceTotal;
			UINT imgId_hand = 0;
			UINT imgId_space = 0;
			if (imgId_hand = agk::GetSpriteImageID(gui::ClickId))
			{
				
				if (imgId_space=agk::GetSpriteImageID(clickId))
				{
					if (imgId_hand == imgId_space) 
					{
						this->BackItem_Space(gui::ClickId);
						gui::Select_Click = false;
						gui::ClickId = 0;
					}
					else
					{
						this->ChangeItemSpace(imgId_space, gui::ClickId);
						this->BackItem_Space(gui::ClickId);
						this->ChangeItemSpace(imgId_hand, clickId);
						this->MoveClick(mx, my);
						gui::Select_Click = true;
					}

				}
				else
				{
					this->ChangeItemSpace(0, gui::ClickId);
					this->BackItem_Space(gui::ClickId);
					agk::SetSpriteVisible(gui::ClickId,0);
					this->ChangeItemSpace(imgId_hand, clickId);
					agk::SetSpriteVisible(clickId, 1);
					gui::Select_Click = false;
					gui::ClickId = 0;
					//this->ChangeItem(imgId, this->ClickId);
				}
			
			
				
				
			}
			else
			{
				gui::Select_Click = true;
				gui::ClickId = clickId;
			}

				
		}
	}

	//click click
	


	
	/*
	float mx = agk::GetPointerX();
	float my = agk::GetPointerY();
	float n = (mx - 23) / 6;
	float nn = (my - 23) / 6;
	agk::SetSpriteVisible(nnn, 0);
	if (n<9 && n>0 && nn <3 && nn>0)
	{
		if ((n - floor(n) < 0.833) && (nn - floor(nn) < 0.833))
		{

			nnn = 28 + floor(n) + floor(nn) * 9;
			agk::SetSpriteVisible(nnn, 1);


		}

	}
	*/
}
void bag::BackItem_Space(UINT spriteId)
{
	UINT spriteId_=spriteId - gui::SpaceTotal - gui::SpaceId;
	UINT i = spriteId_ / gui::Column;
	if (i == gui::Row-1)
		i = gui::Row;
	UINT j = spriteId_ % gui::Column;
	agk::SetSpritePosition(spriteId, gui::ItemOffset_X + j*gui::Offset, gui::ItemOffset_Y + i*gui::Offset);
}

void bag:: MoveClick(float mx, float my)
{
	agk::SetSpritePosition(gui::ClickId,mx- gui::ItemWidth/2,my- gui::ItemHeight/2);
	if (agk::GetPointerReleased())
	{
		gui::Select_Click = false;
	}
}
void bag::ChangeItemSpace(UINT itemId,UINT spriteId)
{
	agk::SetSpriteImage(spriteId, itemId);
	gui::ChangeItemSpace_Contact(itemId, 1, spriteId);



}

bool bag::AddItem(UINT itemId)
{
	UINT itemId_space = gui::SpaceId + gui::SpaceTotal;

	for(UINT i= itemId_space;i<itemId_space + gui::SpaceTotal;i++)
	{
		UINT imgId_be;
		if (imgId_be =agk::GetSpriteImageID(i))
		{
			if (imgId_be == itemId)
			{
				agk::SetSpriteImage(i+1, itemId);
				gui::ChangeItemSpace_Contact(itemId,1,i+1);
				return true;
			}
		}
		else
		{
			agk::SetSpriteImage(i, itemId);
			gui::ChangeItemSpace_Contact(itemId, 1, i);
			return true;
		}
		
	}

	return false;

}