#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define BUFFER_SIZE 1024

int CalculateFileSize(char FileName[]){
    char Buffer[BUFFER_SIZE] = {'\0'};

    int fd = 0,iRet = 0;

    int iSize = 0;

    fd = open(FileName,O_RDONLY);

    if(fd == -1){
        printf("Unable to open file\n");
        return iSize;
    }

    while((iRet = read(fd,Buffer,sizeof(Buffer))) != 0){
        iSize = iSize + iRet;
    }

    close(fd);

    return iSize;
}

void DisplayFile(char *FileName){
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
    
    int iRes = 0;

    printf("Enter file name to display : \n");
    scanf("%[^'\n]s",fName);

    iRes = CalculateFileSize(fName);

    printf("File Size : %d bytes \n",iRes);

    return 0;
}