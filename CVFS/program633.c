#include<stdio.h>

int main(){
    char str[50];
    int iRet = 0;

    iRet = sprintf(str,"Jay Ganesh...");                //print into string

    printf("Value from iRet : %d\n",iRet);

    printf("Data from str is : %s\n",str);

    return 0;
}