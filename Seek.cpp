//#include "LibraryClerk.h"
//#include "SystemBasicFun.cpp"
//#include "Page.cpp"
//#include "FileIo.cpp" 
void SeekBook(Book *HE)//按书名查找
{
	system("cls");
	windows(56,20,text5[0]);
	if(HE->next==NULL)
	{
		gotoxy(PageRetraction+1+40-4+10,PageRetraction-1+7);
		printf("未录入数据!");
		gotoxy(0,20+CensusAll*2+4);
		getch();
		return;
	}
	char bookname[20];
	gotoxy(PageRetraction*2+6,PageRetraction-1+4);
	printf("请输入书的名字：");
	scanf("%s",bookname);
   Book *p=HE->next;
   while(p!=NULL)
   {
     if(strcmp(p->BookName,bookname)==0)
     {
     	gotoxy(PageRetraction*2+6,PageRetraction-1+7);
		printf("%8s%12s%12s%12s%12s%8s%16s%12s","书名","作者名","分类号","出版单位","出版日期","价格","(借:1,未借:0)","修改日期");
		gotoxy(PageRetraction*2,PageRetraction-1+9); 	  
      	printf("%16s%16s%4d%16s%6d.%d.%d%8.2f%10d%14d.%d.%d",p->BookName,p->AutherName,p->ClassNumber,p->PublishUnit,p->PublishTime.year,
	  	p->PublishTime.month,p->PublishTime.day,p->Price,p->Borrow,p->ReviseTime.year,p->ReviseTime.month,p->ReviseTime.day);
	  	getch();
	  	gotoxy(0,20+CensusAll*2+4);
	  	return ;
     }
	 p=p->next;
   }
	gotoxy(PageRetraction+1+40-4+10,PageRetraction-1+7);
	printf("未找到相同数据!");
	getch();
	gotoxy(0,20+CensusAll*2+4);
}

void SeekAuther(Book *HE)//按作者名字查询
{
	int i=0;//作者计数器 
	system("cls");
	windows(56,20+CensusAll*2,text5[1]);
    if(HE->next==NULL)
    {
    	gotoxy(PageRetraction+1+40-4+10,PageRetraction-1+7);
		printf("未录入数据!");
		gotoxy(0,20+CensusAll*2+4);
		getch();
		return;
    }
	char Authername[20];
	gotoxy(PageRetraction*2+6,PageRetraction-1+4);
	printf("请输入作者的名字：");
	scanf("%s",Authername);
   Book *p=HE->next;
   while(p!=NULL)
   {
     if(strcmp(p->AutherName,Authername)==0)
     {
     	gotoxy(PageRetraction*2+6,PageRetraction-1+7);
     	if(i==0)
		printf("%8s%12s%12s%12s%12s%8s%16s%12s","书名","作者名","分类号","出版单位","出版日期","价格","(借:1,未借:0)","修改日期");
		gotoxy(PageRetraction*2,PageRetraction-1+9+i*2);  
      	printf("%16s%16s%4d%16s%6d.%d.%d%8.2f%10d%14d.%d.%d",p->BookName,p->AutherName,p->ClassNumber,p->PublishUnit,p->PublishTime.year,
	  	p->PublishTime.month,p->PublishTime.day,p->Price,p->Borrow,p->ReviseTime.year,p->ReviseTime.month,p->ReviseTime.day);
	  	i++;
     }
	 p=p->next;
	 if(i!=0 && p==NULL)
	 {
		getch();
		gotoxy(0,20+CensusAll*2+4);
		return ;
	 }
   }
   	gotoxy(PageRetraction+1+40-4+10,PageRetraction-1+7);
	printf("未找到相同数据!");
	getch();
	gotoxy(0,20+CensusAll*2+4);
	return ;
}

void Seek()
{
	int choice;
	Book *L;
	choice=SeekPage(36,40,text4);
	ReadDataCreateList(L,FileName);
	switch(choice)
	{
	case 1:
		SeekBook(L);
		break;
	case 2:
		SeekAuther(L); 
		break;
	}
}
