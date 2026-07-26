#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define BUFFER_SIZE 1024

int main(){
    int fd = 0;
    char Buffer[BUFFER_SIZE] = {'\0'};
    int iRet = 0;

    fd = open("program594.c",O_RDONLY);

    if(fd == -1){
        printf("Unable to open file\n");
        return -1;
    }

    while((iRet = read(fd,Buffer,sizeof(Buffer))) != 0){
        write(1,Buffer,iRet);           //imp
        memset(Buffer,'\0',sizeof(Buffer));
    }

    close(fd);

    return 0;
}