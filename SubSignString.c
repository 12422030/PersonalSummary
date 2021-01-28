/*******************************************************
 * ��    ˾: ����ͬ�������Ƽ����޹�˾
 * �� �� ��: SubSignString.c
 * ������: ����ָ���ָ�����ȡ���ַ���
 * �������:
 *           num     ָ����ȡ��
 *           sign    ָ����ַָ���
 *           buf     Ҫ��ֵ��ַ���������
 * �������:
 *           tag     �������ַ���
 * �� �� ֵ:
 *           ȥ�������ַ���
 * ��    ��: zyw
 * ��������: 2008/10
 * �� �� ��:
 * �޸�����:
*******************************************************/

#include "string.h"
#include "stdio.h"

int SubSignString(int num, char sign, char *buf, char *tag)
{
    char *p, *q;
    int i;

    q = buf;

    num--;

    while(num != 0)
    {
      if (*q == sign) num--;
      q++;
	  if(*q=='\0') return 1;	
    }

    p = q;
    i = 0;
    while(*q != sign)
    {
	  if(*q=='\0') return 1;	
      q++;
      i++;
    }
    strncpy(tag, p, i);
    tag[i] = 0;

    return 0;

}

