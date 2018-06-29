/****************************************************
 ��д�ˣ������
 ****************************************************/
 
 /***************************************************
 ������־�� 1.01 �������湦�ܣ�������װ 
 			1.02 �ı�洢·�� ��ͨѶ¼.txt"j
			1.03 ��������
			1.04 �޸�������װbug �޸��༭��ϵ�����bug
			1.05 �����鿴���� �˵�����   
 ***************************************************/ 
 
 /************************************************
 �����Ӵ��룺 
  SetConsoleTextAttribute
       (GetStdHandle(STD_OUTPUT_HANDLE),11) ;
 **************************************************/ 
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NEW    1
#define LOOK   2
#define EDIT   3
#define DELETE 4
#define FIND   5 
#define EXIT   0


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
int find_peo   (int n);   //���� 
void main_menu ();        //�˵� 
void color(const unsigned short corlor1);//��ɫ 

int read_peo()
{
	char str[50];
	int i=0,n=0;
	FILE*fp;
 	if(!(fp=fopen("ͨѶ¼.txt","r")))
  	{
     	printf("error");
     	exit(0);
   	} 
   	fgets(str,50,fp);  //�ѵ�һ�ж��� 
   	while(!feof(fp))
    {
     	i++;
     	fscanf(fp,"%d%s%s%s", &n, peoples[i].name,
  		peoples[i].phone, peoples[i].memo);
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
   	fprintf(fp,"���\t����\t\t\t�绰\t\t\t\t��ע\t\t\n") ;
    for(i=1; i<=n; i++)
    {
		fprintf(fp,"%d\t%s\t\t\t%s\t\t\t%s\n",
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
	scanf("%s",peoples[n].name);			
	printf("��������ϵ�˺���:\n");
	scanf("%s",peoples[n].phone);
	printf("��������ϵ�˱�ע:\n");
	scanf("%s",peoples[n].memo) ;
	save_peo("ͨѶ¼.txt",n);
 	return n;
 }
 
 int look_peo(int n)
 {
 	int i;
 	printf("���\t����\t\t\t�绰\t\t\t\t��ע\n") ;
 	for(i=1;i<=n;i++)
	{
		printf("%d\t%s\t\t\t%s\t\t\t%s\n",
 		         i, peoples[i].name,
		         peoples[i].phone,peoples[i].memo);
  		save_peo("ͨѶ¼.txt",n);
	}
 	    return n;
 }
 int edit_peo(int n)
 {
	int b, change;
	printf("������Ҫ�༭����ϵ�����:\n");
	scanf("%d",&change);
	printf("%d\t%s\t\t\t%s\t%s\n", change, peoples[change].name, 
 			peoples[change].phone,peoples[change].memo);
	printf("������Ҫ�޸ĵ����ݣ�1.���� 2.���� 3.��ע 4.����ȫ�� ��������ȡ��\n");
	scanf("%d",&b);
				
	if(b==1) 
	{
		printf("��������ϵ������:\n");
		scanf("%s",peoples[change].name);				
	}
	else if(b==2) 
	{
		printf("��������ϵ�˺���:\n");
		scanf("%s",peoples[change].phone);				
	}
	else if(b==3) 
	{
		printf("��������ϵ�˱�ע:\n");
		scanf("%s",peoples[change].memo);					
	}
	else if(b==4) 
	{
		printf("��������ϵ������:\n");
		scanf("%s",peoples[change].name) ;
		printf("��������ϵ�˺���:\n");
		scanf("%s",peoples[change].phone);
		printf("��������ϵ�˱�ע:\n");
		scanf("%s",peoples[change].memo) ;					
	}
	save_peo("ͨѶ¼.txt",n);			
 }
 
 int delete_peo(int n)
 {
 	int i = 0, a;
	printf("������Ҫɾ�����˵����:\n");
	scanf("%d",&a);
	printf("%d\t%s\t\t\t%s\t\t\t\t%s\n", 
	          a, peoples[a].name, peoples[a].phone,
 				peoples[a].memo);
	printf("��1ȷ��ɾ��������ȡ��\n");
	scanf("%d",&i);
	if(i==1)
	{
		for(a;a<n;a++)
		{
			strcpy(peoples[a].phone   , peoples[a+1].phone);
			strcpy(peoples[a].name    , peoples[a+1].name);
			strcpy(peoples[a].memo    , peoples[a+1].memo);
		}
	n--;
	save_peo("ͨѶ¼.txt",n);
	}
	return n;
 }
 
 int find_peo(int n)
 {
 	int i,a;
 	char find[40];
 	printf("1.������ 2.���绰 3.����ע 0.\n");
 	scanf("%d",&a);
 	switch(a)
 	{
	 	case 1:
	 	{
	 		printf("����������\n");
	 		scanf("%s",find);
	 		for(i=1;i<=n;i++)
	 		{
		 		if(strcmp(find,peoples[i].name)==0)
		 		{
		 			printf("%d\t%s\t\t\t%s\t\t\t%s\n",
 		               i, peoples[i].name,
		               peoples[i].phone,peoples[i].memo);
		 		}
		 	}
		 	break;
	 	}
	 	case 2:
	 	{
	 		printf("������绰\n");
	 		scanf("%s",find);
	 		for(i=1;i<=n;i++)
	 		{
		 		if(strcmp(find,peoples[i].phone)==0)
		 		{
		 			printf("%d\t%s\t\t\t%s\t\t\t%s\n",
 		               i, peoples[i].name,
		               peoples[i].phone,peoples[i].memo);
		 		}
		 	}
	 		break;
	 	}
	 	case 3:
	 	{
	 		printf("�����뱸ע\n");
	 		scanf("%s",find);
	 		for(i=1;i<=n;i++)
	 		{
		 		if(strcmp(find,peoples[i].memo)==0)
		 		{
		 			printf("%d\t%s\t\t\t%s\t\t\t%s\n",
 		               i, peoples[i].name,
		               peoples[i].phone,peoples[i].memo);
		 		}
		 	}
	 		break;
	 	}
	 	case 0:
	 	{
	 		break;
	 	}
	 	default:printf("��Чָ��!\n"); 
	 	
 	}
 	return n;
 }
 
 void main_menu()
 {
 	printf(" ---------------------------------------------------- \n");
 	printf("|                  ������ָ��                        |\n");
  	printf("|    1.�½���ϵ��  2.�鿴������ϵ��  3.�༭��ϵ��    |\n");
	printf("|    4.ɾ����ϵ��  5.�鿴��ϵ��      0.�˳�          |\n");
	printf("|                                                    |\n");
	printf(" ---------------------------------------------------- \n");
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
	 printf("\t\t  ��ͨ Ѷ ¼��\n");
	 int n=read_peo();     //��ȡ���ݣ����һ������ 
	 
	 system("color f3");
 
     while(1)
     {
     	system("color f3");
        int a;
        main_menu();
        scanf("%d",&a);
        switch(a)
        {
            case NEW   :	n=new_peo   (n);   break;	
            case LOOK  :    n=look_peo  (n);   break;	
            case EDIT  :    n=edit_peo  (n);   break; 
			case DELETE:    n=delete_peo(n);   break;
			case FIND  :    n=find_peo  (n);   break;
	        case EXIT  :    exit(0)  ;
            default    :    printf("��Чָ�\n");
        }
     }
}
