#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool LinearSearch(int Arr[],int iSize,int iNo){
    int iCnt = 0;

    for(iCnt = 0;iCnt<iSize;iCnt++){
        if(Arr[iCnt]==iNo){
            break;
        }
    }
    if(iCnt == iSize){
        return false;
    }
    else{
        return true;
    }
}

int main(){
    int *Brr = NULL;
    int iLength = 0,iCnt = 0,iValue = 0;
    bool bRet = false;

    printf("Enter number of elements :\n");
    scanf("%d",&iLength);

    Brr = (int*)malloc(iLength * sizeof(int));

    printf("Enter the elements : \n");

    for(iCnt = 0;iCnt<iLength;iCnt++){
        scanf("%d",&Brr[iCnt]);
    }

    printf("Enter the element that u want to search:\n");
    scanf("%d",&iValue);

    bRet = LinearSearch(Brr,iLength,iValue);
    
    if(bRet == true){
        printf("Element is present");
    }
    else{
        printf("Element is not present");
    }

    free(Brr);

    return 0;
}