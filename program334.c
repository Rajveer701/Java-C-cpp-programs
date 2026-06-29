#include<stdio.h>

typedef unsigned int UINT;

UINT ToggleBit(UINT iNo,UINT iPos){
    UINT iMask = 0x1;
    UINT iResult = 0;

    iMask = iMask << (iPos - 1);
    iResult = iNo ^ iMask;

    return iResult;
}

int main(){
    UINT iValue = 0,iLoc = 0,iRet=0;

    printf("Enter number : \n");
    scanf("%d",&iValue);

    printf("Enter the bit position to toggle : \n");
    scanf("%d",&iLoc);

    iRet = ToggleBit(iValue,iLoc);

    printf("Updated number : %d\n",iRet);

    return 0;
}