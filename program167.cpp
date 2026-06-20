#include<iostream>
using namespace std;

#pragma pack(1)
class ArrayX
{
    private:
        int *Arr;
        int iSize;

    public:
        //Parameterized Constructor with defalut argument
        ArrayX(int X=5)   
        {
            iSize = X;    // 5 overwrite to 15
            Arr = new int[iSize];       
        }

        ~ArrayX()                       
        {
            delete []Arr;              
        }

};
int main()
{
    ArrayX *aobj1 = new ArrayX();      //Parameterized constructor
    ArrayX *aobj2 = new ArrayX(15);     //Parameterized constructor

    //Function call
    
    
    delete aobj1;
    delete aobj2;

    return 0;
}