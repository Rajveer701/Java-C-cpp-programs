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
    Display(7);    

    return 0;
}