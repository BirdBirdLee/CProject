#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#define COLUM 25
#define SLEEP_TIME 500


/***********************************************
��д��--�����

���ܣ�������Ϸ

������־��3.1������ʵ�֣�������װ 
          3.2���������ֺͲ��ַ��� 
***********************************************/ 
/****************************************************
�����к�������һ���Ļ��ж��Ƿ�©��ܼ�
���԰��������ó�һ������
���䶯��ʵ�֣�������򲻱䣬ͨ���ַ����ڲ����ƣ�����
                  ����һ�ξ͸�str[0]���¸�ֵʵ��
������ʧʵ�֣������˾ͰѸ��ַ���Ϊ���ɼ��Ŀո�
�ж��Ƿ�©�����ַ���������һ��Ԥ��λ�����Ԥ��λ
              ���ǿո����ζ��û�� 
*****************************************************/ 

void gotoxy(int x,int y);
//��������ƶ� 
void judge(char str[], int *score_t, int *score_f);
//���ղ��жϴ�����Ƿ���ȷ
void print(int colum[], char str[],int score_t, int score_f);
//��ӡ����(����) 

int main()
{
	system("color f3");
	int colum[COLUM+1]={0};
	char str[COLUM+2]="                         "; 
	//Ԥ��һ����������Ƿ����䵽��͵���ʧ 
	int score_t = 0, score_f = 0;
	//��Է������������ 
	srand((unsigned)time(NULL));
	
	while(1)
	{	
		int k = 0;
		str[0] = (char)(rand()%26) + 'A';//ÿ�������һ����ĸ 
		colum[0] = rand()%COLUM + 1 ;//ÿ�������һ���������� 
		for(k=COLUM; k>0; k--)
		//���κ���ÿһ����ĸ������������Ԥ��λ 
		{
			str[k] = str[k-1];
			colum[k] = colum[k-1];   
		}	
		judge(str, &score_t, &score_f);	
		//�ж��Ƿ�����Լ��������ȷ���
		system("cls");//���� 
		print(colum, str, score_t, score_f);//��� 
		Sleep(SLEEP_TIME); //ͣ��(�������ӳ�ʱ��) 
	}	
	return 0;
}



void gotoxy(int x,int y)
{
	COORD pos = {x, y};
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut,pos);
}//�������ƶ������ٶȵ� x��y�� 

void judge(char str[],int *score_t,int *score_f)
{
	int judge_n , k;
	for(k=0; k<COLUM;k++ )
	//һ����ఴCOLUM������Ҳ�������һ�ΰ���������ĸ 
	{
		if(kbhit()) //����Ƿ��а������£�����з����� 
		{
			judge_n = 0;
			char ch = getch();
			if((ch)=='\x1B') system("pause");//ESC��ͣ 
			if(ch>='a'&&ch<='z') ch = ch - 'a' + 'A';//��Сд 
			for(k=COLUM; k>0; k--)//�����ж���׶���ĸ 
			{
				if(ch==str[k])
				{
					judge_n = 1;
					str[k] = ' ';//���֮����ĸ��' ' 
					break;
				}
			}
			if(judge_n) (*score_t) ++ ;
			else        (*score_f) ++ ;
			printf("%d %d",*score_t,*score_f); 
			//system("pause");
		}
	}	
	if(str[COLUM]!=' ') (*score_f) ++;
	//���Ԥ��λ����' '˵�����һ��������ĸû�� 
} 

void print(int colum[],char str[],int score_t,int score_f)
{
	int k;
	printf(" True:%3d\t\tFalse:%3d\n", score_t, score_f);
	for(k=0;k<COLUM;k++)  //һ�������ʮ����(������ͬ) 
	{
		gotoxy(colum[k],k+1);
		/*��ʵ��������Ӧ�ü� 1����Ϊ��һ�� 
		  ������ 0 �����ǿճ���һ�и�����*/ 
		printf("%c\n",str[k]);
	}
	printf("---------------Bottom---------------------\n");
}
