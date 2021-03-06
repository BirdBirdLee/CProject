#include "code.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 char* encode(char *prim) 
{
    int i,n,len;
    char code[100];
    char temp_char,trans_char;
    int temp_num,trans_num;
    len = strlen(prim);

    for(i = 0;i < len;i++)
    {
        temp_char = prim[i]; 
        if (temp_char <= 'z' && temp_char >= 'a')
            temp_num = temp_char - 'a' + 1;
        else if (temp_char <= 'Z' && temp_char >= 'A')
            temp_num = temp_char - 'A' + 27;

        trans_num = temp_num*3 % 52;

        if (trans_num > 26 && trans_num <= 52)
            trans_char = 'A' + trans_num - 27;
        else if (trans_num > 0 && trans_num <= 26)
            trans_char = 'a' + trans_num - 1;
            
        if (temp_char >= '0' && temp_char <= '9')
		    temp_num = temp_char - '0' + 53;
		    trans_num = temp_num;
		if (trans_num > 52 && trans_num <= 63)
		    trans_char = '0' + 63 - trans_num; 

        code[i] = trans_char;
    }
    code[len] = '\0';
    return code;
}

char* decode(char *code)
{
    int i,n,len;
    char prim[100];
    char temp_char,trans_char;
    int temp_num,trans_num;
    len = strlen(code);

    for(i = 0;i < len;i++) {
        temp_char = code[i];
        if (temp_char <= 'z' && temp_char >= 'a')
            temp_num = temp_char - 'a' + 1;
        else if (temp_char <= 'Z' && temp_char >= 'A')
            temp_num = temp_char - 'A' + 27;

        n = temp_num % 3;
        switch(n) {
        case 0:
            trans_num = temp_num/3;
            break;
        case 1:
            trans_num = 35 + temp_num/3;
            break;
        case 2:
            trans_num = 18 + temp_num/3;
            break;
        default:
            break;
        }
        if (trans_num > 26 && trans_num <= 52)       
            trans_char = 'A' + trans_num - 27;
        else if (trans_num > 0 && trans_num <= 26)
            trans_char = 'a' + trans_num - 1;
            
        if (temp_char <= '9' && temp_char >= '0')
            temp_num = '0' + 63 - temp_char;
            trans_num = temp_num;
        if (trans_num >52 && trans_num <= 63)
            trans_char = trans_num + '0' - 53;

        prim[i] = trans_char;
    }
    prim[len] = '\0';
    return prim;
}
