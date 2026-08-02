#include<stdio.h>
#include<stdlib.h>

int main(){
    //Conditional Compilation
    #ifdef _WIN32
        printf("Project is running on Windows Platorm\n");
    #else 
        printf("Project is running on Linux / MacOS Platorm\n");
    #endif


    return 0;
}