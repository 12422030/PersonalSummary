/**************************************
* FileName --- tranpin.c
* Author ----- icesky
* Date ------- 9�� 29 2019
*
*
***************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char fullKeyName[60];
    char clearPin[20];
    char accNo[20];
    char pin[50];

    int ret = 0;

    ret=UnionAPIServiceE142(-1, "A24DFF7774F9A89D", "HX.qdtohx.zpk","YL.lxcs33-sm4.zpk","0000000000000000","62299001301272140", "01", "01", 0, "", 0, "", pin, "", "", "");  
    if ( ret < 0  )   
    {   
        printf("ת����Կʧ��[%d]", ret);
        return -1 ;
    }
    printf("ת����Կ�ɹ�\n", pin);
    printf("pinֵΪ---[%s]---\n", pin);
    return 0;
}
