#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#define COLUM 25
#define RAW 20 
#define SLEEP_TIME 500


/***********************************************
��д��--�����

���ܣ�������Ϸ

������־��3.1������ʵ�֣�������װ 
          3.2���������ֺͲ��ַ��ţ���������������ˣ� 
		  3.4�����и����������ܷ�
		  3.5���Զ����ٹ��ܣ������룩ʮ���д�����Ը㶨�������� 
***********************************************/ 
/****************************************************
���䶯��ʵ�֣�������򲻱䣬ͨ���ַ����ڲ����ƣ�����
                  ����һ�ξ͸�str[0]���¸�ֵʵ��
������ʧʵ�֣������˾ͰѸ��ַ���Ϊ���ɼ��Ŀո�
�ж��Ƿ�©�����ַ���������һ��Ԥ��λ�����Ԥ��λ
              ���ǿո����ζ��û�� 
*****************************************************/ 

void gotoxy(int x,int y);
//��������ƶ� 
void judge(char str[],int *score_t,int *score_f,int *score);
//���ղ��жϴ�����Ƿ���ȷ
void print(int colum[],char str[],int score_t,int score_f,int score);
//��ӡ����(����) 

int main()
{
	system("color f3");
	int colum[COLUM+1]={0};
	char str[RAW+2]="                    "; 
	//Ԥ��һ����������Ƿ����䵽��͵���ʧ 
	int score_t = 0, score_f = 0, score = 0; 
	//��Է���������������ܷ� 
	srand((unsigned)time(NULL));
	
	while(1)
	{	
		int k = 0;
		str[0] = (char)(rand()%26) + 'A';//ÿ�������һ����ĸ 
		colum[0] = rand()%COLUM + 1 ;//ÿ�������һ���������� 
		for(k=RAW; k>0; k--)
		//���κ���ÿһ����ĸ������������Ԥ��λ 
		{
			str[k] = str[k-1];
			colum[k] = colum[k-1];   
		}	
		judge(str, &score_t, &score_f, &score);	
		//�ж��Ƿ�����Լ��������ȷ���
		system("cls");//���� 
		print(colum, str, score_t, score_f, score);//��� 
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

void judge(char str[],int *score_t,int *score_f,int *score)
{
	int judge_n , k;
	for(k=0; k<RAW;k++ )
	//һ����ఴRAW������Ҳ�������һ�ΰ���������ĸ 
	{
		if(kbhit()) //����Ƿ��а������£�����з����� 
		{
			judge_n = 0;
			char ch = getch();
			if((ch)=='\x1B') system("pause");//ESC��ͣ 
			if(ch>='a'&&ch<='z') ch = ch - 'a' + 'A';//��Сд 
			for(k=RAW; k>0; k--)//�����ж���׶���ĸ 
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
		}
	}	
	if(str[RAW]!=' ') (*score_f) ++;
	//���Ԥ��λ����' '˵�����һ��������ĸû�� 
	*score = *score_t - 2*(*score_f);
	//�Եļ�һ�֣���Ŀ����� 
} 

void print(int colum[],char str[],int score_t,int score_f,int score)
{
	int k;
	printf(" True:%3d\t\tScore:%3d\t\tFalse:%3d\n", score_t, score, score_f);
	for(k=0;k<RAW;k++)  //һ�����RAW��
	{
		gotoxy(2*colum[k]+1,k+1);
		/* ���ÿ��� Ϊ������*/ 
		printf("%c\n",str[k]);
	}
	printf("-----------------------Bottom-----------------------\n");
}
