#include<stdio.h>

void Display(char *str){
    printf("%s\n",str);
}

int main(){
    char Arr[50] = {'\0'};

    printf("Enter String : \n");
    scanf("%[^'\n']s",Arr); 
    
    Display(Arr);  

    return 0;
}