#include<stdio.h>
int main()
{
    int ret;
    char *srcFile=NULL;
    char *dstFile=NULL;
    char *key=NULL;
    char *keyType=NULL;

    srcFile="HZ_D202004160001.xml.sec";
    dstFile="HZ_D202004160001.xml";
    key="0457BD802D1485B464391C11C3A7235E";
    keyType="S";
    printf("��ڲ���[%s][%s][%s][%s]\n", srcFile, dstFile, key, keyType);

    ret = UnionAPIService_deFile( -1, srcFile, dstFile, key, keyType);
    if( ret < 0)
    {
        printf("�����ļ�ʧ��[%d]!\n", ret);
        return ret;
    }
    printf("�����ļ��ɹ�[%d]\n",ret);
    printf("���ܺ���ļ�Ϊ[%s]\n",dstFile);

    return 0;
}

