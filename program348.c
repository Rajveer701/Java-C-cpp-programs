#include<stdio.h>

typedef unsigned int UINT;

//Position : 3 & 8
int main(){
    UINT iNo = 0;
    UINT iResult = 0;
    UINT iMask1 = 0x00000004;
    UINT iMask2 = 0x00000080;
    UINT iMask = 0;

    iMask = iMask1 | iMask2;

    printf("Enter number : \n");
    scanf("%d",&iNo);

    iResult = iNo ^ iMask;

    printf("Updated Number : %d\n",iResult);

    return 0;
}