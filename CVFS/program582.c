#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>      //only LINUX based OS
#include<string.h>

int main(){
    int fd = 0;
    int iRet = 0;
    char Data[100] = {'\0'};
    char DataX[100]= {'\0'};

    fd = open("Marvellous.txt",O_RDONLY);

    if(fd == -1){
        printf("Unable to open file\n");
    }
    else{
        printf("File opened successfully with fd : %d\n",fd);
        
        iRet = read(fd,Data,13);       //(where,what,how many)

        printf("%d bytes get successflly read\n",iRet);

        printf("Data from file is : %s\n",Data);

        iRet = read(fd,DataX,3); 

        printf("%d bytes get successflly read\n",iRet);

        printf("Data from file is : %s\n",DataX);

        close(fd);
    }

    return 0;
}