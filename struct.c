#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    struct{
        char *name;   //����
        int num;   //ѧ��
        int age;      //����
        char group;   //����С��
        float score;  //�ɼ�
    } stu1,stu2;
#if 1   
    stu1.name ="Tom";
    stu1.num  =12;
    stu1.age  =18;
    stu1.group='A';
    stu1.score=136.5;
    stu2.score=136.5;
#endif    
    printf("%s��ѧ����%d,������%d��%c�����ĳɼ���%.1f\n",stu1.name,stu1.num,stu1.age,stu1.group,stu1.score);
    printf("�ɼ���%.1f\n",stu2.score);
    return 0;
}
