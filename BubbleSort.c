#include<stdio.h>
void main()//������
{
    int a[10];
    int i,j,w;
    int n;
    printf("�����볤��:");
    scanf("%d",&n);
    printf("������[%d]������:\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i]<a[j])
            {
                w=a[i];
                a[i]=a[j];
                a[j]=w;
            }
        }
    }
    printf("�����:\n");
    for(i=0;i<n;i++)
    {
        printf("%4d",a[i]);
    }
    printf("\n");
}
