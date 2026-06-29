#include<stdio.h>

typedef unsigned int UINT;

UINT ToggleBit(UINT iNo,UINT iPos1,UINT iPos2){
    UINT iMask1 = 0x1,iMask2 = 0x1,iMask = 0;
    UINT iResult = 0;

    if(iPos1<1 || iPos1>32 || iPos2<1 || iPos2>32){
        printf("Invalid Bit Position to Toggle\n");
        return iNo;
    }

    iMask1 = iMask1 << (iPos1 - 1);
    iMask2 = iMask2 << (iPos2 - 1);

    iMask = iMask1 | iMask2;

    iResult = iNo ^ iMask;

    return iResult;
}

int main(){
    UINT iValue = 0,iLoc1 = 0,iLoc2 = 0,iRet=0;

    printf("Enter number : \n");
    scanf("%d",&iValue);

    printf("Enter the first bit position to toggle : \n");
    scanf("%d",&iLoc1);

    printf("Enter the second bit position to toggle : \n");
    scanf("%d",&iLoc2);

    iRet = ToggleBit(iValue,iLoc1,iLoc2);

    printf("Updated number : %d\n",iRet);

    return 0;
}