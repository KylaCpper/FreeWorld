//Includes
#include "json/json.h"
#include <fstream>
#include "sol.hpp"
//#pragma comment(lib, "lua51.lib")
#include "freeWorld.h"
#include "overall.h"

// Namespace
using namespace AGK;
using namespace kyla;
using namespace Json;
using namespace std;
sol::state lua;
/*
#define Player Overall.Player;
#define Camera Overall.Camera;
#define Plane Overall.Plane;
#define Scenes Overall.Scenes;
#define Set Overall.Set;

#define BagGui Overall.BagGui;
#define ShortCutBar Overall.ShortCutBar;

#define Dirt Overall.Dirt;
#define DefaultBlock Overall.DefaultBlock;

#define pix Overall.pix;;
*/
app App;




bool ui = false;
UINT deviceWidth;
UINT deviceHeight;

UINT Mouse_Pointer;

UINT mousePointer=0;
UINT mousePointer_be=0;
UINT timeBlocks=0;
UINT *destroyStages = new UINT[10];

void app::Begin(void)
{
	Config.Init("config.json");
	Player=new player();
	Camera=new camera();
	Plane=new plane();
	Scenes=new scenes();
	Set = new set();
	ShortCutBar = new shortCutBar();
	BagGui = new bag(ShortCutBar->NextSpaceId);
	// open some common libraries
	lua.open_libraries(sol::lib::base, sol::lib::package);
	
	//destroyStages init
	Function.DestroyStages_Init(destroyStages);
	//device he wid

	deviceHeight = agk::GetDeviceHeight();
	deviceWidth = agk::GetDeviceWidth();
	agk::SetDisplayAspect(deviceWidth / deviceHeight);
	//agk::SetVirtualResolution(deviceHeight, deviceWidth);
	//physics
	//agk::Create3DPhysicsWorld();
	//agk::Set3DPhysicsGravity(0, -50, 0);
	
	//init place
	//Plane.planeId=agk::CreateObjectBox(100,0.01,100);
	//agk::SetObjectColor(Plane.planeId,66,100,200,255);
	//agk::SetObjectRotation(Plane.planeId,90,0,0);
	//agk::Create3DPhysicsKinematicBody(Plane.planeId);
	//agk::SetObjectShapeBox(Plane.planeId);
	/*
	
	10
	0,5 0,10 0,15
	5,0 10,0 15,0
	5,5 10,10



	for i to 3
		k%1*5,-k%2*5


	5*100 0,0 5,0 5,5 10,5



	*/

	//init box
	//img 
	
	Dirt=new block(Config.GetBlockImg("Dirt"),100);
	DefaultBlock = new block(Config.GetBlockImg("Dirt"), 200);
	//
	Plane->Init(*Dirt,30,2,30);
	Plane->Add(*DefaultBlock,0,30,0);
	//
	pix = new item(Config.GetItemImg("Pickaxe"));
	//agk::Create3DPhysicsKinematicBody(box1);
	//agk::SetObjectShapeBox(box1);


	//agk::LoadImage(2, "assets/images/gui/ui_background.png");
	//chidren image
	//agk::LoadSubImage(chid id img,father id img,"aa12");
	//agk::CreateSprite(2, 2);

	//set sprite 
	//agk::SetSpriteColorAlpha(1,100);
	
	//agk::SetSpriteDepth(2, 2);
	//agk::SetSpriteSize(1, UI_WIDTH, UI_HEIGHT);
	//agk::SetSpritePosition(1, (100 - UI_WIDTH) / 2, (100 - UI_HEIGHT) / 2);
	//agk::SetSpriteSize(1, 640, 640);
	//agk::SetSpriteScale(1,0.5,0.5);


	//agk::SetSpriteActive(BagGui->Id,0);
	//
	

	//
	
	int cc=agk::CreateObjectPlane(3,3);
	agk::SetObjectImage(cc,Config.GetItemImg("Pickaxe"),0);
	agk::SetObjectPosition(cc,10,10,10);
	agk::SetObjectLightMode(cc,0);
	agk::SetObjectTransparency(cc,1);
	agk::SetObjectCollisionMode(cc,0);



	BagGui->AddItem(Config.GetItemImg("Pickaxe"));
	BagGui->AddItem(Config.GetItemImg("Pickaxe_"));

	
	//item click gui
	
	//
	





	//item click gui
	//UINT none = agk::LoadImage("assets/images/items/none.png");

	//agk::SetRawMouseVisible(ui);
 
	//particles
	/*
	agk::Create3DParticles(20,20,10,20);
	agk::Set3DParticlesLife(20,1000);
	agk::Set3DParticlesSize(20, 2);
	agk::Set3DParticlesVelocityRange(20, 0.5, 3.0);
	agk::Set3DParticlesDirectionRange(20,3.0,3.0);
	agk::Set3DParticlesColorInterpolation(20, 1);
	agk::Set3DParticlesImage(20, agk::LoadImage("assets/images/blocks/dirt.png"));
	agk::Add3DParticlesColorKeyFrame(20, 5.0 - 1, 255, 255, 255, 255);
	*/
	
	//shader
	/*
	agk::CreateObjectQuad(8);
	UINT be = agk::LoadShader("assets/shaders/test.vs", "assets/shaders/test.ps");
	agk::SetObjectImage(8, agk::LoadImage("assets/images/blocks/test.png"), 0);
	agk::SetObjectShader(8, be);
	agk::SetObjectPosition(8, 0, 20, 0);
	*/
	//Config.InsertBlockId(200003,20);
	//allow set windows
	//agk::SetWindowAllowResize(0);
	//set windows
	//agk::SetWindowSize(400,400,1,1);

	}

int app::Loop (void)
{
	agk::Print(BagGui->GetItemSpace_Contact(BagGui->SpaceId+ BagGui->SpaceTotal*2-9, "itemId"));
	UINT device_height = agk::GetDeviceHeight();
	UINT device_width = agk::GetDeviceWidth();

	if (deviceHeight != device_height|| deviceWidth != device_width)
	{
		deviceHeight = device_height;
		deviceWidth = device_width;
		agk::SetDisplayAspect(deviceWidth/ deviceHeight);
		agk::UpdateDeviceSize(deviceWidth, deviceHeight);
		//agk::SetVirtualResolution(deviceHeight, deviceWidth);
	}

	//agk::Print(DefaultBlock->Handness);
	//agk::Print(Config.GetBlockId_Root(200003));
	//agk::Print(agk::GetObjectNumMeshes(Plane.planeId));

	agk::Print( agk::ScreenFPS() );
	
	//lua script
	/*
	lua.script_file("test.lua");
	sol::function a_function = lua["test"];
	UINT test = a_function(10);
	agk::Print(test);
	*/
	//q
	if (agk::GetRawKeyPressed(71))
	{
	}
	//g
	if (agk::GetRawKeyPressed(67))
	{
	}
	//f
	if (agk::GetRawKeyPressed(66))
	{
	}
	//49-57 1-9
	for (int i = 49;i <= 57;i++)
	{
		if (agk::GetRawKeyPressed(i))
		{
			ShortCutBar->ChangSelect(i-48);
		}
	}
	//mouse middle wheel
	int mouse_whell = 0;
	if (mouse_whell =agk::GetRawMouseWheelDelta())
	{
		ShortCutBar->ChangSelectWhell(mouse_whell/3);
	}
	agk::Print(mouse_whell);
	if (agk::GetRawKeyPressed(27)) 
	{
		if (BagGui->Visible) 
		{
			goto ESC;
		}
		 
		 ui = !ui;
		//agk::SetRawMouseVisible(ui);
	}
	//e
	if (agk::GetRawKeyPressed(69))
	{
		ESC:
		BagGui->Visible = !BagGui->Visible;
		ui = !ui;
		BagGui->Display();

		


	}
	//Camera.move();
	if (!ui) 
	{

		this->MouseCollision();
		this->MouseLeftCheck();
		//Player.move();
		Player->MoveCollision();
		//agk::Create3DPhysicsDynamicBody(Player.playerId);
		Camera->CameraSync(Player->Id);
		//mouse lock
		float deviceHeight_ = (float)deviceHeight / 2;
		float deviceWidth_ = (float)deviceWidth / 2;
		agk::SetRawMousePosition(50, 50);
	}
	else
	{
		if (BagGui->Visible)
		{
			BagGui->Event();
		}
		
	}
	
	//agk::Step3DPhysicsWorld();
	//agk::DrawObject(Player.playerId);
	//agk::Sync();
	
	agk::Update(0);
	
	//agk::Render2DBack();
	//agk::ClearDepthBuffer();
	agk::Render3D();
	agk::ClearDepthBuffer();
	
	agk::Render2DFront();
	
	//agk::DrawSprite(1);
	agk::Swap();

	return 0; // return 1 to close app
}


void app::End (void)
{

}

void app::MouseCollision()
{
	float cx = agk::GetCameraX(1);
	float cy = agk::GetCameraY(1);
	float cz = agk::GetCameraZ(1);

	float mx = agk::GetPointerX();
	float my = agk::GetPointerY();

	float sx = agk::Get3DVectorXFromScreen(mx, my)*10000;
	float sy = agk::Get3DVectorYFromScreen(mx, my)*10000;
	float sz = agk::Get3DVectorZFromScreen(mx, my)*10000;

	mousePointer = agk::ObjectRayCast(0, cx, cy, cz, sx, sy, sz);
	
}
void app::MouseLeftCheck()
{
	if (agk::GetRawMouseLeftState())
	{

		float distance;
		//mouse -> id
		if (mousePointer != 0)
		{
			distance = agk::GetObjectRayCastDistance(0);
			if (distance <= Config.TouchDistance)
			{
				if (mousePointer_be == mousePointer)
				{
					block *Block;
					UINT rootId = Config.GetBlockId_Root(mousePointer);
					
					this->CheckBlock(rootId, &Block);
					if (Block!=NULL) 
					{
						return;
					}
					UINT handness=Block->Handness;
					agk::Print(handness);
					if (timeBlocks == handness)
					{
						agk::DeleteObject(mousePointer);
						Config.InsertBlockId(mousePointer, 0);
						timeBlocks = 0;
					}
					else
					{
						agk::SetObjectImage(mousePointer, destroyStages[timeBlocks / 10 / (handness / 100)], 1);
						timeBlocks++;
					}
				}
				else 
				{
					Function.BreakCheckBlock(timeBlocks, mousePointer_be);
					mousePointer_be = mousePointer;
				}
				
				




			}
			else
				Function.BreakCheckBlock(timeBlocks, mousePointer_be);
			
		}
		else
			Function.BreakCheckBlock(timeBlocks, mousePointer_be);
		
	}
	else
		Function.BreakCheckBlock(timeBlocks, mousePointer_be);
	
}

void app::CheckBlock(UINT id,block **Block)
{
	if (id == Dirt->Id)
		*Block = Dirt;
	if (id == DefaultBlock->Id)
		*Block = DefaultBlock;

	
}