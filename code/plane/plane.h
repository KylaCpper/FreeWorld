#ifndef _H_PLANE__ 
#define _H_PLANE__
#include "block.h"
namespace kyla
{
	class plane
	{
		public:
			UINT Id;
			plane();
			~plane();
			void Add(block &Block,float x,float y,float z);
			void Init(block &Block, int _x, int _y, int _z);
	};

}
#endif 