#include<iostream>
using namespace std;

#pragma pack(1)
class ArrayX{
    public:
        int *Arr;
        int iSize;

        //default constructor
        ArrayX(){

        }

        //parameterized constructor
        ArrayX(int X){

        }
};

int main(){
    ArrayX aobj1;
    ArrayX aobj2(5);


    cout<<sizeof(aobj1)<<endl;    //12 bytes
    cout<<sizeof(aobj2)<<endl;

    return 0;
}