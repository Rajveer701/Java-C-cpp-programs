//Recursion
#include<stdio.h>

void Display(int iNo){
    static int i=1;
    if(i<=iNo){
        printf("%d \n",i);
        i++;
        Display(iNo);
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