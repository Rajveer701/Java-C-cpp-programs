#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define BUFFER_SIZE 1024

void FileCopy(char FileNameSrc[],char FileNameDest[]){
    char Buffer[BUFFER_SIZE] = {'\0'};
    int fdSrc = 0,fdDest = 0,iRet = 0;

    fdSrc = open(FileNameSrc,O_RDONLY);
    if(fdSrc == -1){
        printf("Unable to open source file \n");
        return;
    }

    fdDest = creat(FileNameDest,0777);
    if(fdDest == -1){
        printf("Unable to create destination file \n");
        return;
    }

    while((iRet = read(fdSrc,Buffer,sizeof(Buffer))) != 0){
        write(fdDest,Buffer,iRet);
        memset(Buffer,'\0',sizeof(Buffer));
    }

    close(fdSrc);
    close(fdDest);

}

int main(){
    char FNameSrc[30] = {'\0'};
    char FNameDest[30] = {'\0'};
    

    printf("Enter the source file name to display : \n");
    scanf("%[^'\n]s",FNameSrc);

    printf("Enter the destination file name : \n");
    scanf(" %[^'\n]s",FNameDest);       //space added

    FileCopy(FNameSrc,FNameDest);

    return 0;
}