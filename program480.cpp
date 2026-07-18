#include<iostream>
using namespace std;

template <class X>

X Maximum(X No1,X No2,X No3){
    if(No1>No2 && No1>No3){
        return No1;
    }
    else if(No2>No1 && No2>No3){
        return No2;
    }
    else{
        return No3;
    }
}

int main(){
    cout<<Maximum(10,51,8)<<endl;
    cout<<Maximum(12.3,12.2,19.6)<<endl;
    cout<<Maximum(17.7f,12.3f,12.2f)<<endl;
   
    return 0;
}