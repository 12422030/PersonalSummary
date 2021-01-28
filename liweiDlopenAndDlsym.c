#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
int main()
{
    void *handle=NULL; 
    int (*fptr)();
    char libSoName[101];


    strcpy(libSoName,"/app/user/liwei/practice/libcaculate.so");

    handle = dlopen(libSoName, RTLD_LAZY|RTLD_GLOBAL);
    if (handle == NULL)
    {
        printf("%s\n",libSoName);
        return -15;
    }   

    printf("��ʼִ��:\n");

    fptr = (int (*)())dlsym(handle, "add");
    if (fptr == NULL)
    {   
        dlclose(handle);
        return -20;
    }   

    printf("%d:\n",fptr(2,10));
    printf("��ʼִ��\n");
    return 0;
}
