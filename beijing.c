#include<time.h> //C���Ե�ͷ�ļ�   
#include<stdio.h> //C���Ե�I/O    
  
void main()   
{   
    time_t now; //ʵ����time_t�ṹ    
    struct tm *timenow; //ʵ����tm�ṹָ��    
    time(&now);   
    //time������ȡ���ڵ�ʱ��(���ʱ�׼ʱ��Ǳ���ʱ��)��Ȼ��ֵ��now    
    timenow = localtime(&now);   
    //localtime�����Ѵ�timeȡ�õ�ʱ��now�����������е�ʱ��(���������õĵ���)    
    printf("Local time is %s/n",asctime(timenow));   
    //�Ͼ���asctime������ʱ��ת�����ַ���ͨ��printf()�������    
}   
