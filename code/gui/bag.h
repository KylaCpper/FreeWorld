#ifndef _H_BAG__ 
#define _H_BAG__
#include "gui.h"
#include "agk.h"
#include "shortCutBar.h"
#include "config.h"
#include <iostream>
#include "json/json.h"
#include <fstream>



namespace kyla 
{
	class bag : public gui 
	{
	public:

		//UINT SpaceTotal = 36;
		void Close();
		void Open();
		void Display();
		void Event();
		void MoveClick(float mx,float my);
		void ChangeItemSpace(UINT itemId,UINT spriteId);
		void BackItem_Space(UINT spriteId);
		bool AddItem(UINT itemId);
		bag(UINT next);
		~bag();
	};



}
#endif 