#define PageRetraction 3
int gotoxy(int x, int y)
{
    COORD coord = {x, y};   
    /*COORD是Windows API中定义的一种结构，表示一个字符在控制台屏幕上的坐标。其定义为：

    typedef struct _COORD {

    SHORT X; // horizontal coordinate

    SHORT Y; // vertical coordinate
    } COORD;*/

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    return 0;
} 

int color(short x)
{
	if(x>=0 && x<=15)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	return 0;	
}

int windows(int w,int h,char text[])			//窗口宽高 
{
	int i,j=0;
	for(j=0;j<h;j++)
	{
		gotoxy(PageRetraction+1,PageRetraction-1+j);
		for(i=0;i<w;i++)
		{			
			if(j==0 || j==h-1)
			{
				printf("※");
			}
			else
			{
				if(i==0 || i==w-1)
					printf("※");
				else
					printf("  ");
			}
		}
		printf("\n");
	}
	gotoxy(PageRetraction+1+w-4,PageRetraction-1);
	printf("%s",text);
	return 0;
}
