#include<stdio.h>

typedef unsigned int UINT;

//Position Dynamic
UINT OffBit(UINT iNo,UINT iPos){
    UINT iMask = 0x1;
    UINT iResult = 0;

    if(iPos<1 || iPos>32){
        printf("Invalid Bit Position to Toggle\n");
        return iNo;
    }

    iMask = iMask << (iPos-1);

    iMask = ~(iMask);

    iResult = iNo & iMask;

    return iResult;
}

int main(){
    UINT iValue = 0,iLoc = 0,iRet=0;

    printf("Enter number : \n");
    scanf("%d",&iValue);

    printf("Enter the bit position to off : \n");
    scanf("%d",&iLoc);

    iRet = OffBit(iValue,iLoc);

    printf("Updated number : %d\n",iRet);

    return 0;
}