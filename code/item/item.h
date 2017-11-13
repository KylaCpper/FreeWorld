#ifndef _H_ITEM__ 
#define _H_ITEM__
#include "agk.h"
#include "itemBase.h"
#include "config.h"
namespace kyla
{
	class item 
	{
		public:
			UINT Id;
			UINT ItemId;
			item(UINT itemId);
			item();
			~item();
			void RightFunction();
	};

}
#endif 