#include<stdio.h>

typedef unsigned int UINT;

//Position : 3 & 7 Toggle
int main(){
    UINT iNo = 0;
    UINT iResult = 0;
    UINT iMask = 0x00000044;

    printf("Enter number : \n");
    scanf("%d",&iNo);

    iResult = iNo ^ iMask;

    printf("Updated Number : %d\n",iResult);

    return 0;
}