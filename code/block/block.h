#ifndef _H_BLOC__ 
#define _H_BLOC__
#include "blockBase.h"
#include "config.h"
namespace kyla
{
	class block : public blockBase
	{
	public:
		
		block(UINT blockImg, int handness);
		~block();

	};
	
}
#endif 