#include<iostream>
using namespace std;

float Maximum(float No1,float No2){
    float Ans;
    if(No1>No2){
        Ans = No1;
    }
    else{
        Ans = No2;
    }
    return Ans;
}

int main(){
    cout<<Maximum(12.3,12.2);
   
    return 0;
}