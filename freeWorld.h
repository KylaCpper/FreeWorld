#ifndef _H_AGK_TEMPLATE_
#define _H_AGK_TEMPLATE_
#include "block.h"
// Link to GDK libraries
#include "AGK.h"

#define DEVICE_WIDTH 640
#define DEVICE_HEIGHT 640
#define DEVICE_POS_X 32
#define DEVICE_POS_Y 32
#define FULLSCREEN false

// used to make a more unique folder for the write path
#define COMPANY_NAME "FreeWorld"

// Global values for the app
class app
{
	public:

		// constructor
		app() { memset ( this, 0, sizeof(app)); }

		// main app functions - mike to experiment with a derived class for this..
		void Begin( void );
		int Loop( void );
		void End( void );
		void MouseCollision();
		void MouseLeftCheck();
		void CheckBlock(UINT id,kyla::block **Block);
};

extern app App;

#endif

// Allow us to use the LoadImage function name
#ifdef LoadImage
 #undef LoadImage
#endif