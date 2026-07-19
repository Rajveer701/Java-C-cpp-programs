//Recursion

// 5678
// 5*6*7*8

#include<stdio.h>

int Summation(int iNo){
    int iDigit = 0;
    static int iSum = 1;
    
    if(iNo != 0){
        iDigit = iNo % 10;
        iSum = iSum * iDigit;
        Summation(iNo/10);   
    }
    return iSum;
}

int main(){
    int iVal = 0;
    int iRet = 0;

    printf("Enter number : \n");
    scanf("%d",&iVal);

    iRet = Summation(iVal);

    printf("Summation is : %d \n",iRet);

    return 0;
}