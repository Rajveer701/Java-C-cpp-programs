#include<stdio.h>

typedef unsigned int UINT;   //typedef is not storage class

int main(){
    UINT iNo = 0;
    UINT iMask = 4;
    UINT iAns = 0;
    
    printf("Enter number : ");
    scanf("%d",&iNo);

    iAns = iNo & iMask;

    if(iAns == iMask){
        printf("3rd bit is ON\n");
    }
    else{
        printf("3rd bit is OFF\n");
    }

    return 0;
}