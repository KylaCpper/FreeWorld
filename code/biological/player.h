#ifndef _H_PLAYER__ 
#define _H_PLAYER__
#include "biological.h"
#include "config.h"
namespace kyla
{
	class player
	{
	public:
		UINT Id;
		player();
		~player();
		void Move();
		void MoveCollision();

		void HandItem();
		
	};
	
}
#endif 