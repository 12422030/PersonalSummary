#include<stdio.h>
#include <fcntl.h>
int main()
{
    char oldname[]="/app/user/liwei/2111.txt";
    char newname[]="/app/user/liwei/111.txt";
    /* prompt for file to rename and new name */
    printf("�������һ���ļ�������·��: ");
#if 0
    gets(oldname);
    printf("�����޸�Ϊ: ");
    gets(newname);
#endif
    /* �����ļ��� */
    if (rename(oldname, newname) == 0)
        printf("�Ѿ����ļ� %s �޸�Ϊ %s.\n", oldname, newname);
    else
        perror("rename");
    return 0;
}
