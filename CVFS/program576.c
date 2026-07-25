#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>      //only LINUX based OS

int main(){
    int fd = 0;

    fd = open("Marvellous.txt",O_RDWR);

    if(fd == -1){
        printf("Unable to open file\n");
    }
    else{
        printf("File opened successfully with fd : %d\n",fd);
        
        write(fd,"Jay Ganesh...",13);       //(where,what,how many)

        close(fd);
    }

    return 0;
}