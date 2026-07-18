#include<iostream>
using namespace std;

template <class X>

X Maximum(X No1,X No2){
    X Ans;
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