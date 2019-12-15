#define ww 10
const char FileNamePW[32]="password.txt";
const int Offset=5;		//加密算法中的偏移值
char InitialPW[32]="123456";
void InputPassword(char *pw)
{
	FILE *fp;
	char p[50];
	int i=0;
	while(i<50)
	{
		p[i]=getch();
		if(p[i]=='\r') break;
		if(p[i]=='\b')
		{
			i=i-1;
			printf("\b\b");
		}
		else
		{
			i=i+1;
			printf("*");
		};
	}
	printf("\n");
	p[i]='\0';
	strcpy(pw,p);
}

void StringEncrpt(char *pw,char *En_pw)
{
	int i=0;
	while(pw[i]!='\0')
	{
		En_pw[i]=(pw[i]+i+Offset)%255;
		i++;	
	}
	En_pw[i]='\0';
}

void WritePW(char *pw)
{
	FILE *fp;
	fp=fopen(FileNamePW,"wt");
	fprintf(fp,"%s",pw);
	fclose(fp);
}

void ReadPW(char *pw)
{
	FILE *fp;
	fp=fopen(FileNamePW,"rt");
	fscanf(fp,"%s",pw);
	fclose(fp);
}

int Login(int w,int h,char text[],int select)		//登陆模块 
{
	char pw[50];					//密码明文 
	char En_pw[50],En_pw1[50];		//密文 
	int x=0,flag=0;
	char New_pw1[23],New_pw2[32];
	FILE *fp;
	if((access(FileNamePW,0))==-1)
	{
		fp=fopen(FileNamePW,"wt");
		StringEncrpt(InitialPW,En_pw);
		fprintf(fp,"%s",En_pw);
		fclose(fp);
	}
	ReadPW(En_pw);
	system("cls");
	windows(w,h,text);
	switch(select)
	{
		case 1:
			{
			gotoxy(PageRetraction+1+w-ww,PageRetraction-1+6+16);
			printf("初始密码：123456");
			gotoxy(PageRetraction+1+w-ww,PageRetraction-1+6);
			printf("输入密码：");
			InputPassword(pw);
			StringEncrpt(pw,En_pw1);
			if(strcmp(En_pw,En_pw1)==0)
			{
				gotoxy(0,34);
				return 1;
			}
			do
			{
				gotoxy(PageRetraction+1+w-ww,PageRetraction-1+6);
				printf("密码错误！输入密码：               ");
				gotoxy(PageRetraction+1+w-ww,PageRetraction-1+6);
				printf("密码错误！输入密码：");
				InputPassword(pw);
				x++;
				StringEncrpt(pw,En_pw1);
				if(strcmp(En_pw,En_pw1)==0)
				{
					gotoxy(0,34);
					return 0;						//这里跳 
				}
			}while(x<3);
			}
		case 0:
			{
			gotoxy(PageRetraction+1+w-ww,PageRetraction-1+6);
			printf("                              ");
			gotoxy(PageRetraction+1+w-ww,PageRetraction-1+8);
			printf("密码错误！强制退出！");
			Sleep(2000);
			gotoxy(0,34);
			exit(0);
			}
		case 2:
			{
			gotoxy(PageRetraction+1+w-ww,PageRetraction-1+6);
			printf("输入密码：");
			InputPassword(pw);
			StringEncrpt(pw,En_pw1);
			if(strcmp(En_pw,En_pw1)!=0)
			{
				x=0;
				do
				{
					gotoxy(PageRetraction+1+w-ww,PageRetraction-1+6);
					printf("密码错误！输入密码：          ");
					gotoxy(PageRetraction+1+w-ww,PageRetraction-1+6);
					printf("密码错误！输入密码：");
					InputPassword(pw);
					x++;
					StringEncrpt(pw,En_pw1);
					if(strcmp(En_pw,En_pw1)==0)
					{
						flag=1;
						break;
					}	
				}while(x<3);
				if(x==3 && flag==0)
				{ 
					gotoxy(PageRetraction+1+w-ww,PageRetraction-1+6);
					printf("                              ");
					gotoxy(PageRetraction+1+w-ww,PageRetraction-1+8);
					printf("密码错误！强制退出！");
					Sleep(2000);
					gotoxy(0,34);
					exit(0);
				}
				else
					flag=1;
			}
			else
				flag=1;
			if(flag==1)
			{
				do
				{
					gotoxy(PageRetraction+1+w-ww,PageRetraction-1+6);
					printf("输入新密码：                    ");
					gotoxy(PageRetraction+1+w-ww,PageRetraction-1+6);
					printf("输入新密码：");
					InputPassword(New_pw1);
					gotoxy(PageRetraction+1+w-ww,PageRetraction-1+6);
					printf("再次输入新密码：                    ");
					gotoxy(PageRetraction+1+w-ww,PageRetraction-1+6);
					printf("再次输入新密码：");
					InputPassword(New_pw2);	
				}while(strcmp(New_pw1,New_pw2)!=0);
			}
			if(strcmp(New_pw1,New_pw2)==0 && strcmp(En_pw,En_pw1)==0)
			{
				StringEncrpt(New_pw1,En_pw);
				WritePW(En_pw);
				gotoxy(PageRetraction+1+w-ww,PageRetraction-1+6);
				printf("                               ");
				gotoxy(PageRetraction+1+w-ww+4,PageRetraction-1+8);
				printf("密码修改成功！");
				gotoxy(0,34);
				getch();	
			}
			break;
			}
	}
	return 0;
}
