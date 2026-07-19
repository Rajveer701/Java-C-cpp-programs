//Recursion

#include<stdio.h>

void Display(int iNo){
    int iDigit = 0;
    
    while(iNo != 0){
        iDigit = iNo % 10;
        printf("%d\n",iDigit);
        iNo = iNo/10;
    }
}

int main(){
    int iVal = 0;

    printf("Enter number : \n");
    scanf("%d",&iVal);

    Display(iVal);

    return 0;
}