#ifndef _H_SHORTCUTBAR__ 
#define _H_SHORTCUTBAR__

#include "agk.h"
#include "config.h"

namespace kyla 
{
	class shortCutBar
	{
		public:
		static const UINT SelectId_Gui = 19;
		static const UINT SpaceId = 1;
		static const UINT SpaceTotal = 9;
		UINT Row = 1;
		UINT NextSpaceId;
		UINT Column = 9;
		UINT UiWidth = 7;
		UINT UiHeight = 7;
		UINT ItemWidth = 5;
		UINT ItemHeight = 5;
		static UINT SelectId;
		static UINT SelectItemId;
		static const UINT ItemOffset_X=20;
		static const UINT ItemOffset_Y=90;
		static const UINT Offset = 7;
		//UINT SpaceTotal = 9;

		static void ChangSelect(UINT num);
		static void ChangSelectWhell(int num);
		static void ChangeSpace(UINT spaceId, UINT itemId);
		static void ChangeSelectItemId();


		shortCutBar();
		~shortCutBar();
	};



}
#endif 