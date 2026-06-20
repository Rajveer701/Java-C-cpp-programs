#include<stdio.h>
#include<stdlib.h>

//TC : O(N)
int Maximum(int Arr[],int iSize){
    int iMax = 0;
    int iCnt = 0;

    iMax = Arr[0];

    for(iCnt = 0;iCnt<iSize;iCnt++){
        if(Arr[iCnt] > iMax){
            iMax = Arr[iCnt];
        }
    }
    return iMax;
}

int main(){
    int *Brr = NULL;
    int iLength = 0,iCnt = 0,iRet = 0;

    printf("Enter number of elements :\n");
    scanf("%d",&iLength);

    Brr = (int*)malloc(iLength * sizeof(int));

    printf("Enter the elements : \n");

    for(iCnt = 0;iCnt<iLength;iCnt++){
        scanf("%d",&Brr[iCnt]);
    }

    iRet = Maximum(Brr,iLength);
    printf("Maximum element is : %d\n",iRet);

    free(Brr);

    return 0;
}