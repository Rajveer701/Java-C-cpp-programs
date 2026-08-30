// ./myexe 10 11

#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]){
    int ans = 0;

    if(argc != 3){
        printf("Invalid Number of Arguments\n");
        return -1;
    }

    ans = atoi(argv[1]) + atoi(argv[2]);  

    printf("Addition is : %d\n",ans);

    return 0;
}