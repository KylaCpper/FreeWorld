#ifndef _H_ITEMBASE__ 
#define _H_ITEMBASE__
#include "agk.h"
namespace kyla
{
	class itemBase
	{
	public:
		UINT Id;
		itemBase();
		~itemBase();
		virtual void RightFunction();
	};
};
#endif 