//Recursion
#include<stdio.h>

void Display(int iNo){
    if(iNo!=0){
        printf("Jay Ganesh!!! %d \n",iNo);
        Display(iNo--);         //issue due to post decrement
    }
}

int main(){
    int iVal = 0;
    printf("Enter number of times to print : \n");
    scanf("%d",&iVal);
    Display(iVal); 
    printf("End of main\n");
    return 0;
}