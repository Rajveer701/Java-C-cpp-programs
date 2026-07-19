//Recursion

// 4 
// 1+2+3+4 = 10
// 7 
// 1+2+3+4+5+6+7 = 28

#include<stdio.h>

int Summation(int iNo){
    static int iSum = 0;
    static int i=1;
    
    if(i<=iNo){
        iSum = iSum + i;
        i++;
        Summation(iNo);
    }
    return iSum;
}

int main(){
    int iVal = 0;
    int iRet = 0;

    printf("Enter frequency : \n");
    scanf("%d",&iVal);

    iRet = Summation(iVal); 

    printf("Sum is : %d\n",iRet);

    return 0;
}