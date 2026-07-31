#include<stdio.h>

int main(){
    int iRet = 0;
    int i = 0,j = 0,k = 0;

    printf("Enter 3 number : \n");
    iRet = scanf("%d %d %d",&i,&j,&k);      //scanf returns no. of values accepted from user

    printf("Value of iRet : %d\n",iRet);

    return 0;
}