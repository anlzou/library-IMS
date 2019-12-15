//#include "LibraryClerk.h"
//#include "SystemBasicFun.cpp"
//int CensusAll=2;
void PrintfData(Book *&L,char TextSort[])
{
	int i;
	Book *p=L->next;
	system("cls");
	windows(56,20+CensusAll*2,TextSort);
	if(p==NULL)
	{
		gotoxy(PageRetraction+1+40-4,PageRetraction-1+6);
		printf("未录入数据!");
	}
	else
	{
		gotoxy(PageRetraction*2+6,PageRetraction-1+4);
		printf("%12s%12s%12s%12s%12s%8s%16s%12s","书名","作者名","分类号","出版单位","出版日期","价格","(借:1,未借:0)","修改日期");
		for(i=0;i<CensusAll || p!=NULL;i++)
   		{ 
		    gotoxy(PageRetraction*2,PageRetraction-1+6+i*2);  	  
      		printf("《%d》%16s%16s%4d%16s%6d.%d.%d%8.2f%10d%14d.%d.%d",i+1,p->BookName,p->AutherName,p->ClassNumber,p->PublishUnit,p->PublishTime.year,
	  	    p->PublishTime.month,p->PublishTime.day,p->Price,p->Borrow,p->ReviseTime.year,p->ReviseTime.month,p->ReviseTime.day);
	  	    //printf("%s%s%d%s%d\.%d\.%d%.2f%d%d\.%d\.%d\n",L->BookName,L->AutherName,L->ClassNumber,L->PublishUnit,L->PublishTime.year,L->PublishTime.month,L->PublishTime.day,
	          //                        L->Price,L->Borrow,L->ReviseTime.year,L->ReviseTime.month,L->ReviseTime.day);	
      		p=p->next;
   		}
	}
	gotoxy(40,20+CensusAll*2+4);
	getch();
	return ;
}
