#include<stdio.h>

void Display(int Arr[],int iSize){
    int iCnt = 0;
    for(iCnt = 0;iCnt < iSize;iCnt++){
         printf("%d\n",Arr[iCnt]);
    }
}

int main(){
    
    int Brr[8] = {10,20,30,40,50,60,88,99};

    Display(Brr,8);

    return 0;
}