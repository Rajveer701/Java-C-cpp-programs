//Recursion

#include<stdio.h>

void Display(int iNo){
    int iDigit = 0;
    
    if(iNo != 0){
        iDigit = iNo % 10;
        iNo = iNo/10;
        Display(iNo);   //Tail Recursion
        printf("%d\n",iDigit);
    }
}

int main(){
    int iVal = 0;

    printf("Enter number : \n");
    scanf("%d",&iVal);

    Display(iVal);

    return 0;
}