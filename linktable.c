#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node{
  int data;
  struct Node *next;
};
int main()
{
    int len,i,val;
    struct Node *p=NULL;
    struct Node *pHead=NULL;
    struct Node *pTail=NULL;
    printf("��������ĳ���:\n");
    scanf("%d",&len);
    pHead=(struct Node *)malloc(sizeof(struct Node));
    if(pHead==NULL)
    {
        return -1;
    }
    pTail=pHead;
    pTail->next=NULL;
    for(i=0;i<len;i++)
    {
        printf("�����%d��ֵ:",i+1);
        scanf("%d",&val);
        struct Node *pNew=NULL;
        pNew=(struct Node *)malloc(sizeof(struct Node));
        if(pNew==NULL)
        {
            printf("��������\n");
            return -2;
        }
        pNew->data=val;
        pNew->next=NULL;
        pTail->next=pNew;
        pTail=pNew;
    }
    printf("��ʼ��ӡ����:\n");
    p=pHead->next;
    while(p!=NULL)
    {
        printf("-%d-",p->data);
        p=p->next;
    }
    printf("\n");
    printf("�����ӡ����:\n");
    return 0;
}
