#ifndef _H_BLOCKBASC__ 
#define _H_BLOCKBASC__
#include "config.h"
#include "json/json.h"
#include "agk.h"

namespace kyla
{
	class blockBase
	{
	public:
		blockBase();
		virtual ~blockBase();
		UINT Id;
		UINT Handness;
	};

}
#endif 