#include<stdio.h>

void Display(int iNo){
    for(int i=1;i<iNo;i++){
        printf("JayGanesh... \n");
    }
}

int main(){
    int iValue = 0;

    printf("Enter the frequency : \n");
    scanf("%d",&iValue);

    Display(iValue);

    return 0;
}