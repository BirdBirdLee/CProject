/****************************************************
 ��д�ˣ������
 ****************************************************/

 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NEW    1
#define LOOK   2
#define EDIT   3
#define DELETE 4
#define FIND   5 
#define EXIT   0
#define PACH "List.txt" 


struct Book 
{
	char login[30];     //��¼�� 
 	char name[50];      //���� 
 	char author[30];    //���� 
 	char kind[30];      //����� 
 	char publisher[50]; //���浥λ
	char time[30];      //����ʱ�� 
  	char price[15];     //�۸� 
};

struct Book books[1000];

int read_book   () ;       //��ȡ�ļ� 
int save_book   (char filename[], int n);//���� 
int new__book   (int n);   //�½� 
int look_book   (int n);   //�鿴���� 
int edit_book   (int n);   //�༭ 
int delete_book (int n);   //ɾ��
int find_book   (int n);   //����
void main_menu  ();         //�˵� 


int main(int argc, char *argv[])
{ 
	 printf("\t\t��ͼ�����Ϣ����ϵͳ��\n");
	 int n = read_book();  //��ȡ���ݣ����һ���鱾���� 
	 
	 system("color f3");  //����������ɫ 
 
     while(1)
     {
     	system("color f3");
        int a;
        main_menu();
        scanf("%d",&a);
        switch(a)
        {
            case NEW   :	n=new_book   (n);   break;	
            case LOOK  :    n=look_book  (n);   break;	
            case EDIT  :    n=edit_book  (n);   break; 
			case DELETE:    n=delete_book(n);   break;
			case FIND  :    n=find_book  (n);   break;
	        case EXIT  :    save_book(PACH,n); exit(0) ;
            default    :    printf("��Чָ�\n");
        }
     }
}

int read_book()
{
	char str[50];
	int i=0,n=0;
	FILE*fp;
 	if(!(fp=fopen(PACH,"r")))
  	{
     	printf("error");
     	exit(0);
   	} 
   	fgets(str,100,fp);  //�ѵ�һ�ж��� 
   	while(!feof(fp))
    {
     	i++;
     	fscanf(fp,"%d%s%s%s%s%s%s%s", &n, books[i].name,
  		books[i].login, books[i].name,books[i].author,
		books[i].kind, books[i].publisher, books[i].time,
		books[i].price );
    }
    fclose(fp);
    return n;
}
         
 
 int save_book(char filename[], int n)
 {
 	int i;
 	FILE* fp=fopen(filename,"w");
	
 	if(fp == NULL)
  	{
     	printf("error");
     	exit(0);
   	}
   	fprintf(fp,"���\t��¼��\t\t����\t\t����\t\t�����\t\t") ;
   	fprintf(fp,"���浥λ\t\t����ʱ��\t\t�۸�\t\t\n") ;
   	
    for(i=1; i<=n; i++)
    {
		fprintf(fp,"%d\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",
	 	i, books[i].login, books[i].name,
	 	books[i].author,books[i].kind, books[i].publisher,
	 	books[i].time,books[i].price);
   	}
    fclose(fp);
    return n;
 }
 
 
 int new_book (int n)
 {
 	n++;
	printf("�������¼��:\n");
	scanf("%s",books[n].login);			
	printf("����������:\n");
	scanf("%s",books[n].name);
	printf("������������:\n");
	scanf("%s",books[n].author) ;
	printf("����������:\n");
	scanf("%s",books[n].kind);
	printf("��������浥λ:\n");
	scanf("%s",books[n].publisher);
	printf("���������ʱ��:\n");
	scanf("%s",books[n].time);
	printf("������۸�:\n");
	scanf("%s",books[n].price);
	save_book(PACH,n);
 	return n;
 }
 
 int look_book(int n)
 {
 	int i;
 	printf("���\t��¼��\t\t����\t\t����\t\t�����\t\t") ;
 	printf("���浥λ\t\t����ʱ��\t\t�۸�\t\t\n") ;
 	for(i=1;i<=n;i++)
	{
		printf("%d\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", 
		i, books[i].login,books[i].name, books[i].author,
		books[i].kind,books[i].publisher,
	 	books[i].time,	books[i].price);
  		save_book(PACH,n);
	}
 	    return n;
 }
 int edit_book(int n)
 {
	int b, change;
	printf("������Ҫ�༭��ͼ�����:\n");
	scanf("%d",&change);
	printf("%d\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", 
			change,	books[change].login, books[change].name,
 			books[change].author,books[change].kind,
 			books[change].publisher, books[change].time,
			books[change].price);
	printf("������Ҫ�޸ĵ����ݣ�1.��¼�� 2.���� 3.���� 4.����� 5.���浥λ\n");
	printf("6.����ʱ�� 7.�۸� 8.����ȫ�� ���ఴ��ȡ��\n");
	scanf("%d",&b);
	switch(b)
	{
		case 1:
		{
			printf("���������޸ĵ�ͼ���¼��:\n");
			scanf("%s",books[change].login);
			break;
		}
		case 2:
		{
			printf("���������޸ĵ�ͼ����:\n");
			scanf("%s",books[change].name);
			break;
		}
		case 3:
		{
			printf("���������޸ĵ�ͼ��������:\n");
			scanf("%s",books[change].author);
			break;
		}
		case 4:
		{
			printf("���������޸ĵ�ͼ������:\n");
			scanf("%s",books[change].kind);
			break;
		}
		case 5:
		{
			printf("���������޸ĵ�ͼ����浥λ:\n");
			scanf("%s",books[change].publisher);
			break;
		}
		case 6:
		{
			printf("���������޸ĵ�ͼ�����ʱ��:\n");
			scanf("%s",books[change].time);
			break;
		}
		case 7:
		{
			printf("���������޸ĵ�ͼ��۸�:\n");
			scanf("%s",&books[change].price);
			break;
		}
		case 8:
		{
			printf("���������޸ĵ�ͼ���¼��:\n");
			scanf("%s",books[change].login);
			printf("���������޸ĵ�ͼ����:\n");
			scanf("%s",books[change].name);
			printf("���������޸ĵ�ͼ��������:\n");
			scanf("%s",books[change].author);
			printf("���������޸ĵ�ͼ������:\n");
			scanf("%s",books[change].kind);
			printf("���������޸ĵ�ͼ����浥λ:\n");
			scanf("%s",books[change].publisher);
			printf("���������޸ĵ�ͼ�����ʱ��:\n");
			scanf("%s",books[change].time);
			printf("���������޸ĵ�ͼ��۸�:\n");
			scanf("%s",books[change].price);
			break;
		}
	} 
	save_book(PACH,n);			
 }
 
 int delete_book(int n)
 {
 	int i, a;
	printf("������Ҫɾ��ͼ����Ϣ�����:\n");
	scanf("%d",&i);
	printf("%d\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", 
		i, books[i].login, books[i].name,
		books[i].author,books[i].kind, books[i].publisher,
	 	books[i].time,	books[i].price);
	printf("��1ȷ��ɾ��������ȡ��\n");
	scanf("%d",&a);
	if(a==1)
	{
		for(i=0;i<n;i++)
		{
			strcpy(books[i].login    , books[i+1].login);
			strcpy(books[i].name     , books[i+1].name);
			strcpy(books[i].author   , books[i+1].author);
			strcpy(books[i].kind     , books[i+1].kind);
			strcpy(books[i].publisher, books[i+1].publisher);
			strcpy(books[i].time     , books[i+1].time);
			strcpy(books[i].price    , books[i+1].price);
		}
	n--;
	save_book(PACH,n);
	}
	return n;
 }
 
 int find_book(int n)
 {
 	int i,a;
 	char find[40];
 	printf("1.������ 2.������ ����ȡ��\n");
 	scanf("%d",&a);
 	switch(a)
 	{
	 	case 1:
	 	{
	 		int judge = 0;
	 		printf("������Ԥ��ѯ�鼮��\n");
	 		scanf("%s",find);
	 		for(i=1;i<=n;i++)
	 		{
		 		if(strcmp(find,books[i].name)==0)
		 		{
		 			printf("%d\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", 
		i, books[i].name,books[i].login, books[i].name,
		books[i].author,books[i].kind, books[i].publisher,
	 	books[i].time,	books[i].price); 
	 				judge++;  //�ж��Ƿ����鼮 
		 		}
		 	}
		 	if(!judge) puts("�����޽����");
		 	break;
	 	}
	 	case 2:
	 	{
	 		int judge = 0;
	 		printf("������Ԥ��ѯͼ��������\n");
	 		scanf("%s",find);
	 		for(i=1;i<=n;i++)
	 		{
		 		if(strcmp(find,books[i].author)==0)
		 		{
		 			printf("%d\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", 
		i, books[i].name,books[i].login, books[i].name,
		books[i].author,books[i].kind, books[i].publisher,
	 	books[i].time,	books[i].price);
		               judge++;
		 		}
		 	}
		 	if(!judge) puts("�����޽����");
	 		break;
	 	}	 	
 	}
 	return n;
 }
 
 void main_menu()
 {
 	printf(" -------------------------------------------------------- \n");
 	printf("|                  ������ָ��                            |\n");
  	printf("|    1.���ͼ����Ϣ  2.�鿴����ͼ��    3.�༭ͼ����Ϣ    |\n");
	printf("|    4.ɾ��ͼ��      5.����ͼ��        0.�˳�������      |\n");
	printf("|                                                        |\n");
	printf(" -------------------------------------------------------- \n");
 } 

