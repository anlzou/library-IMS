#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> //system("color 1");_改变颜色.txt 
#include <windows.h> //Sleep(1);_画爱心.tx
#include <conio.h>
#include <malloc.h>
#include <unistd.h>	//确定文件或文件夹的访问权限
char text[2][20]={"【输入密码】","【修改密码】"};
char text1[]={"【登陆】"};
char text2[]={"【菜单】"};
char text3[]={"【浏览】"};
char text4[]={"【查询】"};
char text5[2][20]={"【按书名查询】","【按作者名查询】"};
char text6[]={"【修改信息】"};
char text7[]={"【文件打开】"};
char TextSort[6][20]={
"【按作者排序】","【按价格排序】","【按分类号排序】",
"【按出版社排序】","【按出版时间排序】","【按修改时间排序】"};
char TextRevise[]={"【修改】"};
char TextDelete[]={"【删除】"}; 
char TextCensus[]={"【统计】"}; 
char FileName[32]="BookData.txt";
char Headline[12][32];
int CensusAll;//统计书本数量 (1-n)
typedef struct LNode
{
	char BookName[20];		//书名 
	char AutherName[20];	//作者名 
	int ClassNumber;		//分类号 1-20
	char PublishUnit[20];	//出版单位 
	struct					//出版时间     %s%s%s%s%d%d%d%f%d%d%d%d
	{
		int year;     //年
		int month;    //月
		int day;      //日
	}PublishTime;
	float Price;			//价格
	struct 					//修改时间 
	{
		int year;
		int month;
		int day;	
	}ReviseTime;
	int Borrow;	//如果书被借出，Borrow=false
	struct LNode *next;		//指针 
}Book;
