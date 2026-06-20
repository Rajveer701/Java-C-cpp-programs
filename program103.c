#include<stdio.h>

void CallByAddress(int *iPtr){
    (*iPtr)++;
}

int main(){
    int iValue = 11;

    printf("Value before func call : %d\n",iValue);

    CallByAddress(&iValue);

    printf("Value after func call : %d\n",iValue);

    return 0;
}