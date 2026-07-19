//Recursion
#include<stdio.h>

void Display(int iNo){
    auto int i=0;
    i=1;
    while(i<=iNo){
        printf("Jay Ganesh!!!%d \n",i);
        i++;
    }
}

int main(){
    int iVal = 0;
    printf("Enter number of times to print : \n");
    scanf("%d",&iVal);
    Display(iVal);    

    return 0;
}