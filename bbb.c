#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main( ) 
{
    char tmpbuf[50]={0x00};
    char buff[]="04nameMODULE_ID05fieldCL04nameTRAN_TIMESTAMP05field14265897904nameSOURCE_BRANCH_NO05fieldPKB.68EDA40753BA04nameBRANCH_ID05field010107";

    get_head_strvalue(buff,"SOURCE_BRANCH_NO",tmpbuf,sizeof(tmpbuf));

}

int get_head_strvalue(char *src, char *head, char *value, int valen)
{
    char *p=NULL;
    char *h=NULL;
    int len=0;
    printf("-----------��ʼ����----------\n");
    sleep(1);
    p = strstr(src,head);
    printf("srcֵΪ----[%s]\n",src);
    sleep(1);
    printf("headֵΪ---[%s]\n",head);
    sleep(1);
    printf("��һ��pֵ--[%s]\n",p);
    sleep(1);
    if(p!=NULL)
    {
        p = p+8+strlen(head);
        printf("�ڶ���pֵ--[%s]\n",p);
        sleep(1);
        printf("p�ĵ�ֵַ--[%d]\n",p);
        sleep(1);
        h = strchr(p,'');
        printf("h��ȡ��ֵ--[%s]\n",h);
        sleep(1);
        printf("h�ĵ�ֵַ--[%d]\n",h);
        sleep(1);
        if(h!=NULL)
        {
            len = h - p;
            printf("p��h�Ĳ�ֵ-[%d]λ---\n",len);
            sleep(1);
            memcpy(value,p,len);
            printf("����[%d]��-[��ȡ������ֵ����Ϊ%s]\n",len,value);
            sleep(1);
            printf("ȡ������---[%s]��ֵ�ĳ��ȵ���p��h�Ĳ�,ͬΪ[%d]\n",value,strlen(value));
            sleep(1);
            if(strcmp(head,"MESSAGE_TYPE")==0)
            {
                value[2]='1';
            }
            printf("-----------���н���----------\n");
        }
    }
    return 0;
}

