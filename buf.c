#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char *p;
    int i,n;

    printf("������Ҫ������ڴ��С:\n");
    scanf("%d",&n);
    
    p=calloc(n+1,sizeof(char));
    if(p==NULL)
    {
      printf("�����ڴ治��!!,���䱨�Ĵ洢λ�ô���!");
      free(p);
      return -1;
    }
    printf("�����ڴ�ɹ�\n");
    for(i=0;i<n;i++)
    {
       p[i]=i+1;
    }
    for(i=0;i<n;i++)
    {
        printf("%d",p[i]);
    }
    printf("\n");
    free(p);
    p=NULL;
    return 0;
}
