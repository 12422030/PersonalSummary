#include<stdio.h>
int search(int A[],int n,int key)
{
    int low=0,high=n-1,mid;
    if(A[low]==key)
        return low;
    else if(A[high]==key)
        return high;
    else
    {
        while(low<=high)
        {
            mid=(low+high)/2;
            if(A[mid]==key)
                return mid; //���ҳɹ�������mid 
            if(key>A[mid])
                low=mid+1;  //�ں�������в��� 
            else
                high=mid-1; //��ǰ�������в��� 
        }
    }
    return -1;  //����ʧ�ܣ�����-1 
}
main()
{
    int A[10]={2,3,5,7,9,11,12,15,19,22},i,n,addr;
    printf("A[10]:");
    for(i=0;i<10;i++)
        printf("%d ",A[i]); //��ʾ����A������
    printf("\n����Ҫ����Ԫ�أ�");
    scanf("%d",&n);     //���������Ԫ��
    addr=search(A,10,n);        //�۰���ҷ��ظ�Ԫ���������е��±�
    if(addr!=-1)        //���ҳɹ�
        printf("%d�������еĵ�%d��Ԫ��\n",n,addr+1);
    else        //����ʧ��
        printf("A��������%d",n);
    return 0;
}
