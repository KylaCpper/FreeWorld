#ifndef _H_GUI__ 
#define _H_GUI__
#include "config.h"
#include "agk.h"
#include "json/json.h"
#include "shortCutBar.h"
using namespace Json;

namespace kyla
{
	class gui
	{
	public:
		UINT Id;
		bool Visible=false;
		UINT Depth = 10;
		UINT ItemId;
		UINT SpaceId;
		UINT SpaceTotal;
		UINT Row = 4;
		UINT Column = 9;
		UINT SelectId = 0;
		UINT ClickId = 0;
		UINT SelectId_Gui = 0;
		UINT NextSpaceId;
		bool Select_Click=false;

		UINT UiWidth;
		UINT UiHeight;
		UINT ItemWidth;
		UINT ItemHeight;
		UINT ItemOffset_X;
		UINT ItemOffset_Y;
		UINT Offset;

		Value ItemSpaces;
	
		virtual void ChangeItemSpace_Contact(UINT itemId, int num, UINT spaceId);
		virtual UINT GetItemSpace_Contact(UINT spaceId,char *type = "itemId");
		virtual void ShortCulBar_Updata();

		gui();
		gui(UINT next);


		virtual ~gui();





	
	};

}
#endif 