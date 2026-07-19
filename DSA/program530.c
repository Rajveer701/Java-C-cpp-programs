//Recursion

// 4 
// 4*3*2*1 = 24
// 5
// 120

#include<stdio.h>

typedef unsigned long int ULONG;

ULONG Factorial(int iNo){
    static ULONG iFact = 1;

    if(iNo > 0){
        iFact = iFact * iNo;
        iNo--;
        Factorial(iNo);
    }

    return iFact;
}

int main(){
    int iVal = 0;
    ULONG iRet = 0;

    printf("Enter frequency : \n");
    scanf("%d",&iVal);

    iRet = Factorial(iVal); 

    printf("Factorial is : %lu\n",iRet);

    return 0;
}