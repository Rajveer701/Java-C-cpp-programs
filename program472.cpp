#include<iostream>
using namespace std;

int AdditionI(int No1,int No2){
    int Ans;
    Ans = No1+No2;

    return Ans;
}

double AdditionD(double No1,double No2){
    double Ans;
    Ans = No1+No2;

    return Ans;
}

float AdditionF(float No1,float No2){
    float Ans;
    Ans = No1+No2;

    return Ans;
}

int main(){
    cout<<AdditionI(11,10)<<"\n";
    cout<<AdditionF(11.5f,10.2f)<<"\n";
    cout<<AdditionD(11.5,10.2)<<"\n";

    return 0;
}