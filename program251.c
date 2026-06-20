#include<stdio.h>

int count(const char *str){
    int iCount = 0;

    while(*str != '\0'){
        if(*str == 'a' || *str == 'A'){
            iCount++;
        }
        str++;  
    }
    return iCount;
}

int main(){
    char Arr[50] = {'\0'};
    int iRet = 0;

    printf("Enter String : \n");
    scanf("%[^'\n']s",Arr); 
    
    iRet = count(Arr);  
    printf("Frequency is : %d\n",iRet);

    return 0;
}