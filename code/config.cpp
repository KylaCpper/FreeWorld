#include "config.h"
#include <iostream>
#include "json/json.h"
#include <fstream>

using namespace kyla;
using namespace std;
using namespace Json;
Value root;
CharReaderBuilder rbuilder;
StreamWriterBuilder wbuilder;
string errs;
float config::BlockSide = 4;
float config::PlayerSide = 4;
float config::MoveSpeed = 1;
float config::DownSpeed = 1;
float config::JumpSpeed = 1;
UINT config::TouchDistance = 20;

Value config::Item;
Value config::Block;
Value config::Gui;

Value config::BlocksId;
char temp[10];
void config::Init(char *url)
{
	ifstream config_file("config.json");
	bool parsingSuccessful = Json::parseFromStream(rbuilder, config_file, &root, &errs);
	Config.ItemInit();
	Config.BlockInit();
	Config.GuiInit();

	
	//config_file >> root;
	//std::string document = Json::writeString(wbuilder, root);
	/*
	Config.BlockSide = Config.GetConfig_Float("Block", "Side");
	Config.PlayerSide = Config.GetConfig_Float("Player", "Side");
	Config.MoveSpeed = Config.GetConfig_Float("Player", "MoveSpeed");
	Config.DownSpeed = Config.GetConfig_Float("Player", "DownSpeed");
	Config.JumpSpeed = Config.GetConfig_Float("Player", "JumpSpeed");
	Config.TouchDistance = Config.GetConfig_UINT("Player", "TouchDistance");
	*/

	
}
void config::ItemInit()
{
	Config.Item["Pickaxe"]=1;
	Config.Item["Pickaxe_"]=2;
	agk::LoadImage(Config.GetItemImg("Pickaxe"),"assets/images/items/iron_pickaxe.png");
	agk::LoadImage(Config.GetItemImg("Pickaxe_"),"assets/images/items/diamond_pickaxe.png");
}

void config::GuiInit()
{
	Config.Gui["Background"] = agk::LoadImage("assets/images/gui/background.png");
	Config.Gui["Stats_Icons"] = agk::LoadImage("assets/images/gui/stats_icons.png");
	Config.Gui["Widgets"] = agk::LoadImage("assets/images/gui/widgets.png");

}
void config::BlockInit()
{
	Config.Block["Dirt"] = agk::LoadImage("assets/images/blocks/dirt.png");;
}



void config::InsertBlockId(UINT id,UINT Id ) 
{
	sprintf(temp, "%d", id);
	Config.BlocksId[temp] = Id;
}
UINT config::GetBlockId_Root(UINT id)
{
	sprintf(temp, "%d", id);
	return Config.BlocksId.get(temp, 0).asUInt();
}

UINT config::GetBlockImg(char *key0)
{
	UINT data = Config.Block.get(key0, 0).asUInt();
	return data;
}
UINT config::GetItemImg(char *key0)
{
	UINT data = Config.Item.get(key0, 0).asUInt();
	return data;
}
UINT config::GetGuiImg(char *key0)
{
	UINT data = Config.Gui.get(key0, 0).asUInt();
	return data;
}

char* config::GetConfig(char *key0)
{
	string str = root.get(key0, "null").asString();
	UINT len = str.length();
	char *data = new char[len + 1];
	strcpy(data, str.c_str());
	//delete str;
	return data;
}
char* config::GetConfig_Err(char *key0)
{
	string str = root[key0].asString();
	UINT len = errs.length();
	char *data =    new char[len + 1];
	strcpy(data, errs.c_str());

	return data;
}
UINT config::GetConfig_UINT(char *key0)
{
	UINT data = root.get(key0, "null").asUInt();
	return data;
}

UINT config::GetConfig_UINT(char *key0, char *key1)
{
	UINT data = root[key0][key1].asUInt();
	return data;
}
float config::GetConfig_Float(char *key0)
{
	float data = root.get(key0, "null").asFloat();
	return data;
}

float config::GetConfig_Float(char *key0,char *key1)
{
	float data = root[key0][key1].asFloat();
	return data;
}

void config::GetConfig_Arr(float *arr,char *key0)
{

	//*arr = root.get(key0, "null").asFloat;
}
char* config::GetConfig(char *key0, char *key1)
{
	Json::Value temp_value = root[key0];
	string str = temp_value[key1].asString();
	UINT len = str.length();
	char *data = new char[len + 1];
	strcpy(data, str.c_str());
	return data;
}
char* config::GetConfig(char *key0,char *key1, char *key2)
{
	Json::Value temp_value = root[key0];
	temp_value = temp_value[key1];
	string str = temp_value[key2].asString();
	UINT len = str.length();
	char *data = new char[len + 1];
	strcpy(data, str.c_str());
	return data;
}
char* config::GetConfig(char *key0, char *key1, char *key2, char *key3)
{
	Json::Value temp_value = root[key0];
	temp_value = temp_value[key1];
	temp_value = temp_value[key2];
	string str = temp_value[key3].asString();
	UINT len = str.length();
	char *data = new char[len + 1];
	strcpy(data, str.c_str());
	return data;
}
