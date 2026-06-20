#include<stdio.h>

void updateString(char *str){
    while(*str != '\0'){
        if(*str=='l'){
            *str = 'L';
        }
        str++;  
    }
}

int main(){
    char Arr[50] = {'\0'};

    printf("Enter String : \n");
    scanf("%[^'\n']s",Arr); 
    
    updateString(Arr);  
    printf("Updated string is : %s\n",Arr);

    return 0;
}