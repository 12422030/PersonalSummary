#include <stdio.h>
static int esbxmlBaseGetResmsg(char *buf);
void main()
{
    char buf[55]=  {"����Ϊʲô������ְ����Ҳ��֪����ѽ��Ρ��Ϊʲô������"};

    esbxmlBaseGetResmsg(buf);
    
    printf("%s\n",buf);
}
static int esbxmlBaseGetResmsg(char *buf)
{
    int i=0, j=0, k=0, n=0;
#if 1 /*<1> Add by gaozhiqiang @20170526 BEG*/
    int f=0;
    int len=0;
#endif /*<1> END*/


    for(i=0; i<50; i++)
    {
        k = buf[i];
        if( k<0 || k>128 )       /** Ϊ���� **/
        {
            n++;
            if ( n%2 == 0 )
                j=0;
            else
                j=1;
        }
        else
        {
            j=0;
        }
    }

    if((buf[49]<0 || buf[49]>128) && j==1)
    {
        buf[49] = '\0';
        printf("������ַ�Ϊ���֣��ص���buf[49]%d\n", buf[49]);
    }
    else
    {
        printf("������ַ������������������! buf[49]%d\n", buf[49]);
    }
#if 1 /*<1> Add by gaozhiqiang @20170526 BEG*/
    len=strlen(buf);
    while(1)
    {
        if( buf[f]>0 && buf[f]<128) 
        {
            f+=1;
            continue;
        }
        else if( buf[f]<0 || buf[f]>128) 
        {
            if( buf[f+1]<0 || buf[f+1]>128) 
            {
                f+=2;
                continue;
            }
            else
            {
                buf[f] = '\0';
                break;
            }
        }
        if(f>=len) break;
    }
#endif /*<1> END*/
    buf[50]=0;

    return 0;
}
/********************#esbxmlBaseGetResmsg-END#********************/
