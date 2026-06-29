#include<stdio.h>

typedef unsigned int UINT; 

int main(){
    UINT iNo = 0;
    UINT iMask = 0x1;
    UINT iPos = 0;
    UINT iAns = 0;
    
    printf("Enter number : ");
    scanf("%d",&iNo);

    printf("Enter position : ");
    scanf("%d",&iPos);

    iMask = iMask << (iPos-1);      // left shift (visualise)
    iAns = iNo & iMask;

    if(iAns == iMask){
        printf("Bit is ON\n");
    }
    else{
        printf("Bit is OFF\n");
    }

    return 0;
}