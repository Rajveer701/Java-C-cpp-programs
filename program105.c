#include<stdio.h>

void Display(int *iPtr){
    printf("%D\n",*iPtr);      // * --> value
}

int main(){
    
    int Arr[5] = {10,20,30,40,50};

    Display(Arr);

    return 0;
}