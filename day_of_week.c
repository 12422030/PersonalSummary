/**��������Ϊ���ڼ�**/
#include<stdio.h>
int main()
{
    int res;
    res=day_of_week(2020,05,12);
    switch(res)
    {
        case 1:
            printf("����һ\n");
            break;
        case 2:
            printf("���ڶ�\n");
            break;
        case 3:
            printf("������\n");
            break;
        case 4:
            printf("������\n");
            break;
        case 5:
            printf("������\n");
            break;
        case 6:
            printf("������\n");
            break;
        case 0:
            printf("������\n");                                                                                     
            break;
    }
    return 0;
}
int day_of_week(int y, int m, int d)
{
        static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
        y -= m < 3;
        return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}
