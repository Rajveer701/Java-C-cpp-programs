#include<iostream>
using namespace std;

float Maximum(float No1,float No2){
    float Ans;

    //Ternary operand
    // ? -> if      : -> else
    (No1 > No2) ? Ans = No1 : Ans = No2;     
                                            
    return Ans;
}

int main(){
    cout<<Maximum(12.3,12.2);
   
    return 0;
}