#include<stdio.h>
#include<string.h>

int main(){
    char str[] = {"Jay Ganesh"};
    int iRet = 0;
    iRet = strlen(str); //func

    printf("Length of string is : %d\n",iRet);

    iRet = sizeof(str);  //operator 

    printf("Size of string is : %d\n",iRet);

    return 0;
}