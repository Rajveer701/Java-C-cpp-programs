//Recursion
#include<stdio.h>

void Display(int iNo){
    while(iNo!=0){
        printf("Jay Ganesh!!!%d \n",iNo);
        iNo--;
    }
}

int main(){
    int iVal = 0;
    printf("Enter number of times to print : \n");
    scanf("%d",&iVal);
    Display(iVal); 

    return 0;
}