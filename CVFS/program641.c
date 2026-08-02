#include<stdio.h>
#include<stdlib.h>

int main(){
    //Conditional Compilation
    #ifdef _WIN32
        system("dir")
    #else 
        system("ls");
    #endif


    return 0;
}