#include<stdio.h>

int main(){
    char Arr[50] = {'\0'};

    printf("Enter String : \n");
    scanf("%[^'\n']s",Arr);   //ReGex -> Regular Expression

    printf("Entered String is : %s\n",Arr);

    return 0;
}