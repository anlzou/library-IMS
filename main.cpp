#include "LibraryClerk.h"
#include "IncludeFile.h"
int main()
{
	int choice;
	Book *L;
	EnterPage();//Logo页面 
	choice=LoginPage(30,30,text1);//登陆菜单
	Login(30,30,text[choice-1],choice);
	while(1)
	{
		choice=MenuPage(36,40,text2);//主菜单
		switch(choice)
		{
			case 1:
				Input();//输入保存数据 
				break;
			case 2:
				Compositor();//排序浏览 
				break;
			case 3:
				Seek();//查询 
				break;
			case 4:
				Revise();//修改 
				break;
			case 5:
				Delete();//删除 
				break;
			case 6:
				Census();//统计 
				break;
		}
	}
	return 0;
}
