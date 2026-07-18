#include<iostream>
using namespace std;

template <class T> 

T Addition(T No1,T No2){
    T Ans;
    Ans = No1+No2;

    return Ans;
}


int main(){
    //template instataneous --> 3 func built seperately for main call
    cout<<Addition(11,10)<<"\n";
    cout<<Addition(11.5f,10.2f)<<"\n";
    cout<<Addition(11.5,10.2)<<"\n";

    return 0;
}