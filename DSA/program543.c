//Recursion

#include<stdio.h>

int SummationofElements(int Arr[],int iSize){
    static int i=0;
    static int iSum = 0;
    if(i<iSize){
        iSum = iSum + Arr[i];
        i++;
        SummationofElements(Arr,iSize);
    }
    return iSum;
}

int main(){
    int Brr[] = {10,20,30,40,50};
    int iRet = 0;
    
    iRet = SummationofElements(Brr,5);

    printf("Addition is : %d\n",iRet);

    return 0;
}