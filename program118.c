#include<stdio.h>

int Summation(int Arr[],int iSize){
    int iCnt = 0;
    int iSum = 0;
    for(iCnt = 0;iCnt < iSize;iCnt++){
        iSum = iSum + Arr[iCnt];
    }
    return iSum;
}

int main(){
    
    int iLength = 4;
    int Brr[iLength];
    int iCnt = 0;
    int iRet = 0;

    printf("Enter elements of array : ");
    for(iCnt = 0;iCnt < iLength;iCnt++){
        scanf("%d\n",&Brr[iCnt]);
    }

    iRet = Summation(Brr,iLength);

    printf("Addition of all Array elements is : %d",iRet);

    return 0;
}