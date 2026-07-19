//Recursion

// 4 
// 4*3*2*1 = 24
// 5
// 120


#include<stdio.h>

int Factorial(int iNo){
    int iFact = 1;

    while(iNo!=0){
        iFact = iFact * iNo;
        iNo--;
    }

    return iFact;
}

int main(){
    int iVal = 0;
    int iRet = 0;

    printf("Enter frequency : \n");
    scanf("%d",&iVal);

    iRet = Factorial(iVal); 

    printf("Factorial is : %d\n",iRet);

    return 0;
}