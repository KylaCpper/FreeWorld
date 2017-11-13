#ifndef _H_OVERALL__ 
#define _H_OVERALL__
#include "config.h"

#include "camera.h"
#include "player.h"
#include "block.h"
#include "plane.h"
#include "scenes.h"
#include "set.h"
#include "gui.h"
#include "bag.h"
#include "shortCutBar.h"
#include "function.h"
#include "itemBase.h"
#include "item.h"
namespace kyla
{
	static player *Player;
	static camera *Camera;
	static plane *Plane;
	static scenes *Scenes;
	static set *Set;

	static bag *BagGui;
	static shortCutBar *ShortCutBar;

	static block *Dirt;
	static block *DefaultBlock;

	static item *pix;












	class overall
	{
	public:
		overall();
		~overall();
		/*
		static player *Player;
		static camera *Camera;
		static plane *Plane;
		static scenes *Scenes;
		static set *Set;

		static bag *BagGui;
		static shortCutBar *ShortCutBar;

		static block *Dirt;
		static block *DefaultBlock;

		static item *pix;
		*/

	};
	/*
	extern player *Player;
	extern camera *Camera;
	extern plane *Plane;
	extern scenes *Scenes;
	extern set *Set;

	extern bag *BagGui;
	extern shortCutBar *ShortCutBar;

	extern block *Dirt;
	extern block *DefaultBlock;

	extern item *pix;
	*/
	//extern overall;
}
#endif 