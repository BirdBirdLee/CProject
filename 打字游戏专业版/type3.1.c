#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#define COLUM 25
#define SLEEP_TIME 500


/***********************************************
编写人--李鹤鹏

功能：打字游戏

更新日志：3.1：功能实现，函数封装 
          
***********************************************/ 
/****************************************************
发现行和列设置一样的话判断是否漏打很简单
所以把行列设置成一样的了
掉落动画实现：输出规则不变，通过字符串内部后移，并且
                  后移一次就给str[0]重新赋值实现
按对消失实现：按对了就把该字符变为不可见的空格
判断是否漏按：字符串最后面加一个预留位，如果预留位
              不是空格就意味着没打 
*****************************************************/ 

void gotoxy(int x,int y);
//输出坐标移动 
void judge(char str[], int *score_t, int *score_f);
//接收并判断打的字是否正确
void print(int colum[], char str[],int score_t, int score_f);
//打印界面(所有) 

int main()
{
	system("color f3");
	int colum[COLUM+1]={0};
	char str[COLUM+2]="                         "; 
	//预留一个用来检测是否下落到最低点消失 
	int score_t = 0, score_f = 0;
	//打对分数，错误分数 
	srand((unsigned)time(NULL));
	
	while(1)
	{	
		int k = 0;
		str[0] = (char)(rand()%26) + 'A';//每次随机第一个字母 
		colum[0] = rand()%COLUM + 1 ;//每次随机第一个出现列数 
		for(k=COLUM; k>0; k--)
		//依次后移每一个字母，列数，包括预留位 
		{
			str[k] = str[k-1];
			colum[k] = colum[k-1];   
		}	
		judge(str, &score_t, &score_f);	
		//判断是否打字以及打的字正确与否
		system("cls");//清屏 
		print(colum, str, score_t, score_f);//输出 
		Sleep(SLEEP_TIME); //停顿(下落与延迟时间) 
	}	
	return 0;
}



void gotoxy(int x,int y)
{
	COORD pos = {x, y};
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut,pos);
}//这个光标移动函数百度的 x列y行 

void judge(char str[],int *score_t,int *score_f)
{
	int judge_n , k;
	for(k=0; k<COLUM;k++ )
	//一次最多按COLUM个键，也就是最多一次按完所有字母 
	{
		if(kbhit()) //检测是否有按键按下，如果有返回真 
		{
			judge_n = 0;
			char ch = getch();
			if((ch)=='\x1B') system("pause");//ESC暂停 
			if(ch>='a'&&ch<='z') ch = ch - 'a' + 'A';//大小写 
			for(k=COLUM; k>0; k--)//最先判断最底端字母 
			{
				if(ch==str[k])
				{
					judge_n = 1;
					str[k] = ' ';//点击之后字母变' ' 
					break;
				}
			}
			if(judge_n) (*score_t) ++ ;
			else        (*score_f) ++ ;
			//printf("%d %d",*score_t,*score_f); 
			//system("pause");
		}
	}	
	if(str[COLUM]!=' ') (*score_f) ++;
	//如果预留位不是' '说明最后一个下落字母没打 
} 

void print(int colum[],char str[],int score_t,int score_f)
{
	int k;
	printf(" True:%3d\t\tFalse:%3d\n", score_t, score_f);
	for(k=0;k<COLUM;k++)  //一次输出二十五行(行列相同) 
	{
		gotoxy(colum[k],k+1);
		/*其实本来列数应该减 1，因为第一列 
		  坐标是 0 ，但是空出第一列更美观*/ 
		printf("%c\n",str[k]);
	}
	printf("---------------Bottom---------------------\n");
}
