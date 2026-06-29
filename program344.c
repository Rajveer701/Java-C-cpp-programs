#include<stdio.h>

typedef unsigned int UINT;

//Position : 9 & 17
int main(){
    UINT iNo = 0;
    UINT iResult = 0;
    UINT iMask = 0x00010100;

    printf("Enter number : \n");
    scanf("%d",&iNo);

    iResult = iNo ^ iMask;

    printf("Updated Number : %d\n",iResult);

    return 0;
}