#include "gui.h"
#include <iostream>
#include "agk.h"
#include "json/json.h"
#include <fstream>

using namespace kyla;
using namespace std;
using namespace Json;
gui::gui()
{


}
gui::gui(UINT next):SpaceId(next)
{

}
gui::~gui()
{

}
//�ı���Ʒ�͸���id  json��ϵ
void gui::ChangeItemSpace_Contact(UINT itemId, int num, UINT spaceId)
{
	char temp[10];
	sprintf(temp, "%d", spaceId);
	//string temp = std::to_string(spaceId);
	//if (!this->ItemSpaces[temp]["itemId"].asUInt())
	//{
		//this->ItemSpaces[temp]["itemId"] = itemId;
	//}
	
	//num += this->ItemSpaces[temp]["num"].asUInt();
	this->ItemSpaces[temp]["num"] = num;
	this->ItemSpaces[temp]["itemId"] = itemId;
	
	//delete temp;
}
//��ȡ��Ʒ�͸���id  json��ϵ
UINT gui::GetItemSpace_Contact(UINT spaceId,char *type)
{
	char temp[10];
	sprintf(temp, "%d", spaceId);
	return this->ItemSpaces[temp][type].asUInt();
	
}
//���ӺͶ�Ӧ����gui �� 9���� ����
void gui::ShortCulBar_Updata()
{
	UINT itemId;
	for (UINT i = 0;i < 9;i++)
	{
		itemId = this->GetItemSpace_Contact(this->SpaceId + this->SpaceTotal * 2 - 9 + i, "itemId");
		shortCutBar::ChangeSpace(i + 1, itemId);
		
			
	}
	
}

//virtual