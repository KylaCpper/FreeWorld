#ifndef _H_CONFIG__ 
#define _H_CONFIG__
#include "json/json.h"
#include "agk.h"
//typedef unsigned int UINT;

namespace kyla
{

	static class config
	{
	public:
		static float BlockSide;
		static float PlayerSide;
		static float MoveSpeed;
		static float DownSpeed;
		static float JumpSpeed;
		static UINT TouchDistance;
		//item id img
		static Json::Value  Item;
		static const  UINT Pickaxe = 100;
		static const  UINT Pickaxe_ = 101;
		//gui img
		static Json::Value  Gui;
		static const UINT Background_Img = 1;
		static const UINT Stats_Icons = 2;
		static const UINT Widgets = 3;
		//block img
		static Json::Value  Block;

		//
		static Json::Value BlocksId;
		//Id = source block id ,id = block id
		static UINT GetBlockImg(char *key);
		static UINT GetItemImg(char *key);
		static UINT GetGuiImg(char *key);
		static void InsertBlockId(UINT id, UINT Id);
		static UINT GetBlockId_Root(UINT id);
		static char *GetConfig_Err(char *key0);
		static char *GetConfig(char *key0);
		static float GetConfig_Float(char *key0);
		static float GetConfig_Float(char *key0, char *key1);
		static UINT GetConfig_UINT(char *key0);
		static UINT GetConfig_UINT(char *key0, char *key1);
		static void GetConfig_Arr(float *arr, char *key0);
		static char *GetConfig(char *key0, char *key1);
		static char *GetConfig(char *key0, char *key1,char *key2);
		static char *GetConfig(char *key0, char *key1, char *key2,char *key3);
		static void Init(char *url);
		static void ItemInit();
		static void GuiInit();
		static void BlockInit();
	};

	extern config Config;
}
#endif 