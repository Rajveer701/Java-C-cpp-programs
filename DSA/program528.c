//Recursion

// 4 
// 4*3*2*1 = 24
// 5
// 120

#include<stdio.h>

unsigned long int Factorial(int iNo){
    unsigned long int iFact = 1;

    while(iNo!=0){
        iFact = iFact * iNo;
        iNo--;
    }

    return iFact;
}

int main(){
    int iVal = 0;
    unsigned long int iRet = 0;

    printf("Enter frequency : \n");
    scanf("%d",&iVal);

    iRet = Factorial(iVal); 

    printf("Factorial is : %lu\n",iRet);

    return 0;
}