#include <stdio.h>

// aceaceace c

char* delete(char str[], char ch)
{
	char *p, *q;
	p = q = str;
	while(*p!='\0')
	{
		if(*p!=ch)
		{
			*q = *p;
			q++;
		}
		p++;
	}
	*q = '\0';  //��'\0' 
	return str;
}

int main()
{
	char str[50], delete_char; 
	scanf("%s",str);
	getchar();                 //��ȡ�س����߿ո� 
	delete_char = getchar();
	printf("%s", delete(str,delete_char));
	return 0;
}