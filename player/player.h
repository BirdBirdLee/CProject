#ifndef _ZZZ_USER_H___
#define _ZZZ_USER_H___

typedef struct User
{
	int num;            //�û���� 
	char id[30];        //�û�id 
	char password[30];  //�û����� 
}User;

extern User users[500];

extern char user_name[30];              //��ǰ�û����� 
extern int user_n;                      //��ǰ�ܹ��û����� 

void read_user(const char filename[]);	//��ȡ�û���¼
void save_user(const char filename[]);	//�����û���¼
User* get_user(const char* user_id);
					//ͨ���û�����ȡ�����û��ṹ������ 
int is_exist_user(const char* user_id); //�Ƿ���ڸ��û�
void login_or_regist_window();          //��¼��ע�ᴰ�� 
int login();                     		//��¼��̨����
void regist();                   		//ע�� 
void delete_user();						//ɾ���û� 
void change_password();					//�������� 
char* encode(char *prim);      		    //����
char* decode(char *code);               //���� 
void create_if_not_exit();
//�����洢�����û���Ϣ��txt�����û���������Ϊ�ļ��� 

#endif //_ZZZ_USER_H___
