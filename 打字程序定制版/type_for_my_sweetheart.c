#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

/***********************************************
��д��--�����

���ܣ�������Ϸ

������־��3.1������ʵ�֣�������װ 
          3.2���������ֺͲ��ַ���  
		  3.3�����и����������ܷ�
		  3.4���Զ����ٹ��� 
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
void judge(char str[],int *score_t,int *score_f,int *score,int colum[]);
//���ղ��жϴ�����Ƿ���ȷ
void print(int colum[],char str[],int score_t,int score_f,int score);
//��ӡ����(����) 

int COLUM;
int RAW;
int SLEEP_TIME;
int RANK; 
double SPEED_UP;

int score_t = 0, score_f = 0, score = 0; 

int main()
{
	int i;
	FILE *fp_read;
	fp_read = fopen("Info.txt", "r");
	fscanf(fp_read, "%d%d%d%d%lf", 
					&COLUM,
					&RAW,
					&SLEEP_TIME, 
					&RANK,
					&SPEED_UP);
	
	system("color f3");
	
	int *colum;
	colum = (int*)malloc(sizeof(int)*(COLUM + 1));
	for(i=0; i<COLUM+1; i++)
		colum[i] = 0;
	char *str; 
	str = (char*)malloc(sizeof(char)*(RAW + 2));
	for(i=0; i<RAW+2; i++)
		str[i] = ' ';
	str[i] = '\0';
	//Ԥ��һ����������Ƿ����䵽��͵���ʧ 
	//��Է���������������ܷ� 
	int sleep_time;
	srand((unsigned)time(NULL));
	
	while(score>=-50)
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
		judge(str, &score_t, &score_f, &score, colum);	
		//�ж��Ƿ�����Լ��������ȷ���
		system("cls");//���� 
		print(colum, str, score_t, score_f, score);//���
		int rank = score;
		sleep_time = SLEEP_TIME;
		for(k=1;rank>0;k++)
		{
			rank -= RANK;
			sleep_time = (int)(sleep_time*SPEED_UP);
		} 	
		Sleep(sleep_time); //ͣ��(�������ӳ�ʱ��) 
	}	
	gotoxy(COLUM/2, RAW/2);
	printf("GAME OVER!\n");
	system("pause");
	return 0;
}



void gotoxy(int x,int y)
{
	COORD pos = {x, y};
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut,pos);
}//�������ƶ������ٶȵ� x��y�� 

void judge(char str[],int *score_t,int *score_f,int *score,int colum[])
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
					gotoxy(2*colum[k]+1,k+1);
					printf("\b ");
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
