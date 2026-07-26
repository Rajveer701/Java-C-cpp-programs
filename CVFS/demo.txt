#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>      //only LINUX based OS
#include<string.h>

int main(){
    int fd = 0;
    int iRet = 0;
    char Data[] = "Marvellous Infosystems"; 

    fd = open("Marvellous.txt",O_RDWR | O_APPEND);

    if(fd == -1){
        printf("Unable to open file\n");
    }
    else{
        printf("File opened successfully with fd : %d\n",fd);
        
        iRet = write(fd,Data,strlen(Data));       //(where,what,how many)

        printf("%d bytes get successflly written\n",iRet);

        close(fd);
    }


    return 0;
}