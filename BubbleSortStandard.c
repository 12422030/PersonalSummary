#include<stdio.h>
int main()
{
    int i,N;
    int matrix[4];
    /**
    printf("�������鳤��:\n");
    scanf("%d",&N);
    **/
    printf("���������Ԫ�ظ���:\n");
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
      printf("��[%d]�������ֵΪ:",i+1);
      scanf("%d",&matrix[i]);
    }
    bubbleSort(matrix,N);
    printf("������ֵΪ:\n");
    for(i=0;i<N;i++)
    {
      printf("%-3d",matrix[i]);
    }

    return 0;
}

void bubbleSort(int *arr,int n)
{
    int m,i,j;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-1-i;j++)
            if(arr[j]>arr[j+1])
            {
                m=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=m;
            }
}
