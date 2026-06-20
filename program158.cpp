#include<iostream>
using namespace std;

#pragma pack(1)
class ArrayX{
    public:
        int *Arr;
        int iSize;


        //parameterized constructor
        ArrayX(int X){

            cout<<"Inside Constructor\n";
            iSize = X;              //Characteritics intialization
            Arr = new int(iSize);   //Resource allocation
        }

        //Destructor
        ~ArrayX(){
            cout<<"Inside Destructor\n";
            delete []Arr;           //Resource deallocation
        }
};

int main(){
    ArrayX aobj1(5);

    return 0;
}