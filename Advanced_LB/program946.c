// ./myexe 10 11

#include <stdio.h>

int main(int argc,char *argv[]){
    int ans = 0;

    if(argc != 3){
        printf("Invalid Number of Arguments\n");
        return -1;
    }

    ans = argv[1] + argv[2];    // Error due to char* data

    printf("Addition is : %d",ans);

    return 0;
}