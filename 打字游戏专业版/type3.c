#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#define COLUM 25
#define SLEEP_TIME 500

/*
�����к�������һ���Ļ��ж��Ƿ�©��ܼ�
*/ 


void gotoxy(int x,int y)
{
	COORD pos = {x, y};
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut,pos);
}//�������ƶ������ٶȵ� x��y�� 


int main()
{
	system("color f3");
	int k, colum[COLUM+1]={0};
	char str[COLUM+2]="                         "; 
	//Ԥ��һ����������Ƿ����䵽��͵���ʧ 
	int score_true = 0, score_false = 0;
	char ch;
	srand((unsigned)time(NULL));
	while(1)
	{	
		//for(int i=0; i<10;i++)
		//{
			str[0] = (char)(rand()%26) + 'A';
			//ÿ�������һ����ĸ 
			colum[0] = rand()%COLUM + 1 ;
			//ÿ�������һ���������� 
			Sleep(SLEEP_TIME);                //ͣ�� 
			for(k=COLUM; k>0; k--)
			//���κ���ÿһ����ĸ������������Ԥ��λ 
			{
				str[k] = str[k-1];
				colum[k] = colum[k-1];   
			}
			if(str[COLUM]!=' ') score_false++;
			//���Ԥ��λ����' '˵�����һ��������ĸû�� 
			
			for(k=0; k<COLUM;k++ )
			//һ����ఴCOLUM������Ҳ�������һ�ΰ���������ĸ 
			{
				if(kbhit())    //����Ƿ��а������£�����з����� 
				{
					int k;
					int judge = 0;
					char ch = getch();
					if((ch)=='\x1B') system("pause");
					//ESC��ͣ 
					for(k=15; k>0; k--)//�����ж���׶���ĸ 
					{
						if(ch==str[k])
						{
							judge = 1;
							str[k] = ' ';//���֮����ĸ��' ' 
							break;
						}
					}
					if(judge) score_true ++ ;
					else score_false ++ ;
				}
			}	
			system("cls");
			printf(" True:%3d\t\tFalse:%3d\n",score_true,score_false);
			for(k=0;k<COLUM;k++)  //һ�������ʮ����(������ͬ) 
			{
				gotoxy(colum[k],k+1);
				/*��ʵ��������Ӧ�ü� 1����Ϊ��һ�� 
				  ������ 0 �����ǿճ���һ�и�����*/ 
				printf("%c\n",str[k]);
			}
			printf("---------------Bottom---------------------\n");				
		//}
	}	
	return 0;
}
