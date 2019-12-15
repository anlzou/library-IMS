//#include "LibraryClerk.h"
//#include "SystemBasicFun.cpp"
float f(float x, float y, float z) 
{
	float a;
    a = x*x + 9.0f/4.0f*y*y + z*z - 1;
    return a*a*a - x*x*z*z*z - 9.0f/80.0f*y*y*z*z*z;
}

float h(float x, float z) 
{
	float y;
    for (y = 1.0f; y >= 0.0f; y -= 0.001f)
	{
        if (f(x, y, z) <= 0.0f)
            return y;
	}
    return 0.0f;
}

int EnterPage()
{
	float z,x,v;
	int i;
    for (z = 1.5f; z > -1.5f; z -= 0.06f) 
	{
        for (x = -1.5f; x < 1.5f; x += 0.030f) 
		{
            v = f(x, 0.0f, z);
            if (v <= 0.0f) 
			{
                float y0 = h(x, z);
                float ny = 0.01f;
                float nx = h(x + ny, z) - y0;
                float nz = h(x, z + ny) - y0;
                float nd = 1.0f / sqrtf(nx*nx + ny*ny + nz*nz);
                float d = (nx + ny - nz)*nd*0.5f + 0.5f;
                color(4);
                putchar(".:-=+*#%@"[(int)(d * 5.0f)]);
            }
            else
                putchar(' ');
        }
        putchar('\n');
    }
    //system("mode con cols=120 lines=44");//CMD窗口宽和高 
    color(14);//字体黄色 
    gotoxy(34,46);
    printf("欢迎进入\"红心图书馆信息管理系统\"！\n");
    gotoxy(34,48);
    printf("Designers by Anlzou with JingHong.");
    for(i=5;i>=0;i--)
    {
    	Sleep(1000);
    	gotoxy(40,45);
    	printf("启动成功！即将登陆：%d\n",i);
    }
    Sleep(1000);
    color(15);//字体白色 
    system("cls");
	return 0;
}

int LoginPage(int x,int y,char text[])
{
	int choice;
	windows(x,y,text);
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+6);
	printf("1 登陆");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+8);
	printf("2 修改密码");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+10);
	printf("0 退出");
	do
	{
		gotoxy(PageRetraction+1+x-4,PageRetraction-1+15);
		printf("选择操作：");
		printf("          ");
		gotoxy(PageRetraction+1+x-4,PageRetraction-1+15);
		printf("选择操作：");
		scanf("%d",&choice);
	}while(choice<0  || choice>2);
	if(choice==0)
	{
		gotoxy(0,34);
		exit(0);
	}	
	return choice;
}

int MenuPage(int x,int y,char text[])
{
	int choice;
	system("cls");
	windows(x,y,text);
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+6);
	printf("1 录入");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+8);
	printf("2 浏览");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+10);
	printf("3 查询");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+12);
	printf("4 修改");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+14);
	printf("5 删除");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+16);
	printf("6 统计");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+18);
	printf("0 退出");
	do
	{
		gotoxy(PageRetraction+1+x-4,PageRetraction-1+23);
		printf("选择操作：");
		printf("          ");
		gotoxy(PageRetraction+1+x-4,PageRetraction-1+23);
		printf("选择操作：");
		scanf("%d",&choice);
	}while(choice<0  || choice>6);
	if(choice==0)
	{
		gotoxy(0,44);
		exit(0);
	}	
	return choice;
}

int CompositorPage(int x,int y,char text[])
{
	int choice;
	system("cls");
	windows(x,y,text);
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+6);
	printf("1 按作者排序");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+8);
	printf("2 按价格排序");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+10);
	printf("3 按分类号排序");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+12);
	printf("4 按出版社排序");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+14);
	printf("5 按出版时间排序");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+16);
	printf("6 按修改时间排序");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+18);
	printf("0 返回主菜单");
	do
	{
		gotoxy(PageRetraction+1+x-4,PageRetraction-1+23);
		printf("选择操作：");
		printf("          ");
		gotoxy(PageRetraction+1+x-4,PageRetraction-1+23);
		printf("选择操作：");
		scanf("%d",&choice);
	}while(choice<0  || choice>6);	
	return choice;
}

int SeekPage(int x,int y,char text[])
{
	int choice;
	system("cls");
	windows(x,y,text);
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+6);
	printf("1 按书名查询");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+8);
	printf("2 按作者名查询");
	do
	{
		gotoxy(PageRetraction+1+x-4,PageRetraction-1+13);
		printf("选择操作：");
		printf("          ");
		gotoxy(PageRetraction+1+x-4,PageRetraction-1+13);
		printf("选择操作：");
		scanf("%d",&choice);
	}while(choice<=0  || choice>=3);	
	return choice;
}

int RevisePage(int x,int y,char text[])
{
	int choice;
	system("cls");
	windows(x,y,text);
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+6);
	printf("1 修改书的名字");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+8);
	printf("2 修改作者名字");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+10);
	printf("3 修改书分类号");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+12);
	printf("4 修改出版单位");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+14);
	printf("5 修改出版年");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+16);
	printf("6 修改出版月");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+18);
	printf("7 修改出版日");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+20);
	printf("8 修改书的价格");
	gotoxy(PageRetraction+1+x-4,PageRetraction-1+22);
	printf("9 修改书的借还");
	do
	{
		gotoxy(PageRetraction+1+x-4,PageRetraction-1+27);
		printf("选择操作：");
		printf("          ");
		gotoxy(PageRetraction+1+x-4,PageRetraction-1+27);
		printf("选择操作：");
		scanf("%d",&choice);
	}while(choice<=0  || choice>=10);
	return choice;
}
