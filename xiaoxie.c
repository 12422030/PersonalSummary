/**
 * Сдת����д
**/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[21]="qwertyASDFG";
    char newname[21];
    int i,l,c,max,min;
    l=strlen(s);
    for(i=0;i<l;i++)
    {
      if(isupper(s[i]))
      {
          max++;
          printf("ԭ�ַ������д�д��ĸ!\n");
          c=tolower(s[i]);
      }
      else
      {
          min++;
          printf("ԭ�ַ�������Сд��ĸ!\n");
          c=s[i];
      }
          newname[i]=c;
    }
    /**�����ʼ��**/
    newname[l]=0;
    printf("�ַ�������Ϊ[%ld]-----ת��ǰ���ַ���Ϊ[%s]\n",l,s);
    printf("�ַ�������Ϊ[%ld]-----ת������ַ���Ϊ[%s]\n",l,newname);
    printf("��д��ĸ��[%d]��-----Сд��ĸ��[%d]��\n",max,min);
    return 0;
}
