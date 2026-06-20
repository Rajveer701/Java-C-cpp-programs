#include<stdio.h>

void CallByValue(int iNo){
    iNo++;
}

int main(){
    int iValue = 11;

    printf("Value before func call : %d\n",iValue);

    CallByValue(iValue);     //CallByValue(11)

    printf("Value after func call : %d\n",iValue);

    return 0;
}