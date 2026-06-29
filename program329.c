#include<stdio.h>

typedef unsigned int UINT;

int main(){
    UINT iMask = 0xFFFFFFFF;  //largest val of int
    
    printf("%u\t%X\n",iMask,iMask);

    return 0;
}