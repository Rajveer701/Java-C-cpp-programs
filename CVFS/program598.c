#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define BUFFER_SIZE 1024

void DisplayFile(char FileName[]){
    char Buffer[BUFFER_SIZE] = {'\0'};

    int fd = 0,iRet = 0;

    fd = open(FileName,O_RDONLY);

    if(fd == -1){
        printf("Unable to open file\n");
        return;
    }

    while((iRet = read(fd,Buffer,sizeof(Buffer))) != 0){
        write(1,Buffer,iRet);           //imp
        memset(Buffer,'\0',sizeof(Buffer));
    }

    close(fd);
}

int main(){
    char fName[30] = {'\0'};

    printf("Enter file name to display : \n");
    scanf("%[^'\n]s",fName);

    DisplayFile(fName);

    return 0;
}