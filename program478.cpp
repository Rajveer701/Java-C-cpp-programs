#include<iostream>
using namespace std;

template <class T>

T Maximum(T No1,T No2){
    T Ans;
    if(No1>No2){
        Ans = No1;
    }
    else{
        Ans = No2;
    }
    return Ans;
}

int main(){
    cout<<Maximum(10,12)<<endl;
    cout<<Maximum(12.3,12.2)<<endl;
    cout<<Maximum(12.3f,12.2f)<<endl;
   
    return 0;
}