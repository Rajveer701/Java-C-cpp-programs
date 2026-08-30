// ./myexe 10 11

#include <stdio.h>

int main(int argc,char *argv[]){
    int ans = 0;

    if(argc != 3){
        printf("Invalid Number of Arguments\n");
        return -1;
    }

    ans = (int)argv[1] + (int)argv[2];    // Warning

    printf("Addition is : %d",ans);

    return 0;
}