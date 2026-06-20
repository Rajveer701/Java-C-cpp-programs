#include<stdio.h>

int strlenX(char * const str){
    int iCount = 0;

    while(*str != '\0'){
        iCount++;
        str++;  //str = str + 1
    }
    return iCount;
}

int main(){
    char Arr[50] = {'\0'};
    int iRet = 0;

    printf("Enter String : \n");
    scanf("%[^'\n']s",Arr); 
    
    iRet = strlenX(Arr);
    printf("Length of String is : %d\n",iRet);

    return 0;
}