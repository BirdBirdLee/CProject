/****************************************************
 ��д�ˣ������
 ****************************************************/
 /***************************************************
 ������־��1.01 �������湦�ܣ�������װ 
 ***************************************************/ 
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define NEW 1
#define LOOK 2
#define EDIT 3
#define DELETE 4
#define EXIT 0

struct People
{
	char phone[20];
 	char name[30];
  	char memo[100];
};

struct People peoples[100];

int read_peo   () ;       //��ȡ�ļ� 
int save_peo   (char filename[], int n);//���� 
int new__peo   (int n);       //�½� 
int look_peo   (int n);   //�鿴 
int edit_peo   (int n);   //�༭ 
int delete_peo (int n);   //ɾ�� 
void main_menu ();        //�˵� 
void color(const unsigned short corlor1);//��ɫ 

int read_peo()
{
	int i=0,n=0;
	FILE*fp;
 	if(!(fp=fopen("d:\\tongxunlu.txt","r")))
  	{
     	printf("error");
     	exit(0);
   	} 
   	while(!feof(fp))
    {
     	i++;
     	fscanf(fp,"%d%s%s%s", &n, &peoples[i].name,
  		&peoples[i].phone, &peoples[i].memo);
    }
    fclose(fp);
    return n;
}
         
 
 int save_peo(char filename[], int n)
 {
 	int i;
 	FILE* fp=fopen(filename,"w");
	
 	if(fp == NULL)
  	{
     	printf("error");
     	exit(0);
   	}
   	
    for(i=1; i<=n; i++)
    {
		fprintf(fp,"%d \t\t\t\t %s \t\t\t\t %s \t\t\t\t %s\n",
		        i, peoples[i].name,peoples[i].phone, 
		        peoples[i].memo);
   	}
    fclose(fp);
    return n;
 }
 
 
 int new_peo (int n)
 {
 	n++;
	printf("��������ϵ������:\n");
	scanf("%s",&peoples[n].name);			
	printf("��������ϵ�˺���:\n");
	scanf("%s",&peoples[n].phone);
	printf("��������ϵ�˱�ע:\n");
	scanf("%s",&peoples[n].memo) ;
	save_peo("d:\\tongxunlu.txt",n);
 	return n;
 }
 
 int look_peo(int n)
 {
 	int i;
 	printf("��� \t\t\t\t ���� \t\t\t\t �绰 \t\t\t\t ��ע \n") ;
 	for(i=1;i<n+1;i++)
	{
		printf("%d \t\t\t\t %s \t\t\t\t %s \t\t\t\t %s \n",
 		         i, peoples[i].name,
		         peoples[i].phone,peoples[i].memo);
  		save_peo("d:\\tongxunlu.txt",n);
	}
 	    return n;
 }
 int edit_peo(int n)
 {
	int b, change;
	printf("������Ҫ�༭����ϵ�����:\n");
	scanf("%d",&change);
	printf("%d \t %s \t %s \t %s \n", n, peoples[change].name, 
 			peoples[change].phone,peoples[change].memo);
	printf("������Ҫ�޸ĵ����ݣ�1.���� 2.���� 3.��ע 4.����ȫ�� ��������ȡ��\n");
	scanf("%d",&b);
				
	if(b==1) 
	{
		printf("��������ϵ������:\n");
		scanf("%s",&peoples[change].name);				
	}
	else if(b==2) 
	{
		printf("��������ϵ�˺���:\n");
		scanf("%s",&peoples[change].phone);				
	}
	else if(b==3) 
	{
		printf("��������ϵ�˱�ע:\n");
		scanf("%s",&peoples[change].memo);					
	}
	else if(b==4) 
	{
		printf("��������ϵ������:\n");
		scanf("%s",&peoples[change].name) ;
		printf("��������ϵ�˺���:\n");
		scanf("%s",&peoples[change].phone);
		printf("��������ϵ�˱�ע:\n");
		scanf("%s",&peoples[change].memo) ;					
	}
	save_peo("d:\\tongxunlu.txt",n);			
 }
 
 int delete_peo(int n)
 {
 	int i = 0, a;
	printf("������Ҫɾ�����˵����:\n");
	scanf("%d",&a);
	printf("%d \t %s \t %s \t %s \n", 
	          a, peoples[a].name, peoples[a].phone,
 				peoples[a].memo);
	printf("��1ȷ��ɾ��������ȡ��\n");
	scanf("%d",&i);
	if(i==1)
	for(a;a<n;a++)
	{
		strcpy(peoples[a].phone   , peoples[a+1].phone);
		strcpy(peoples[a].name    , peoples[a+1].name);
		strcpy(peoples[a].memo    , peoples[a+1].memo);
	}
	n--;
	save_peo("d:\\tongxunlu.txt",n);
 }
 
 void main_menu()
 {
 	printf(" --------------------------------------------------------- \n");
  	printf("|��������� 1.�½���ϵ��  2.�鿴������ϵ��  3.�༭��ϵ�� |\n");
	printf("|             4.ɾ����ϵ��  0.�˳�                         |\n");
	printf(" --------------------------------------------------------- \n");
 } 
 
 /*void color(const unsigned short color1) 
 {
 	if(color1>=0&&color1<=15)
 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color1);
 	else
 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
 }*/
 
 
int main(int argc, char *argv[])
{ 
	 int n=read_peo();
	 
	 system("color fc");
 
     while(1)
     {
        int a;
        main_menu();
        scanf("%d",&a);
        switch(a)
        {
            case NEW   :n++;
	printf("��������ϵ������:\n");
	scanf("%s",&peoples[n].name);			
	printf("��������ϵ�˺���:\n");
	scanf("%s",&peoples[n].phone);
	printf("��������ϵ�˱�ע:\n");
	scanf("%s",&peoples[n].memo) ;
	save_peo("d:\\tongxunlu.txt",n);;   break;	
            case LOOK  :    look_peo  (n);   break;	
            case EDIT  :    edit_peo  (n);   break; 
			case DELETE:    delete_peo(n);   break;
	        case EXIT  :    exit(0)  ;
            default    :    printf("��Чָ�\n");
        }
     }
}
