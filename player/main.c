#include <stdio.h>
#include "player.h"

int main()
{
	int instruction;
	login_or_regist_window();
	create_if_not_exit();
	while(1)
	{
		printf("1.ɾ���û�  2.�������� 0.�˳�\n");
		scanf("%d", &instruction);
		switch(instruction)
		{
			case 1:	delete_user();		break;
			case 2:	change_password();	break;
			case 0:	exit(0);
			default: printf("��Чָ�\n"); 
		}
	}
	return 0;
}
