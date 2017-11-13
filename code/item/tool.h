#ifndef _H_TOOL__ 
#define _H_TOOL__
#include "agk.h"
#include "itemBase.h"
namespace kyla
{
	class tool :public itemBase
	{
	public:
		tool(UINT id);
		~tool();
		void RightFunction();
	};

}
#endif 