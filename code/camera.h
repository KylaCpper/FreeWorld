#ifndef _H_CAMERA__
#define _H_CAMERA__  
#include "config.h"
namespace kyla
{
	class camera
	{
		
		public:
			camera();
			~camera();
			void CameraSync(int playerId);
			UINT MainCamera;
			
	};


}

#endif 