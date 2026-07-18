#include<iostream>
using namespace std;

float Maximum(float No1,float No2){
    if(No1>No2){
        return No1;
    }
    else{
        return No2;
    }
}

int main(){
    cout<<Maximum(12.3,12.2);
   
    return 0;
}