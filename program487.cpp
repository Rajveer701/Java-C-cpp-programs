#include<iostream>
using namespace std;

class ArrayX{
    public:
        int *Arr;
        int Size;

        ArrayX(int No){
            Size = No;
            Arr = new int(Size);
        }
        ~ArrayX(){
            delete []Arr;
        }
        void Accept(){
            int i = 0;
            cout<<"Enter the elements : \n";

            for(i=0;i<Size;i++){
                cin>>Arr[i];
            }
        }
        void Display(){
            int i = 0;
            cout<<"Elements of the array are : \n";

            for(i=0;i<Size;i++){
                cout<<Arr[i]<<"\n";
            }
        }
        int Summation(){
            int i = 0;
            int sum = 0;

            for(i=0;i<Size;i++){
                sum = sum + Arr[i];
            }
            return sum;
        }
};

int main(){
    ArrayX aobj(5);

    aobj.Accept();
    aobj.Display();
    cout<<aobj.Summation()<<"\n";
    
    return 0;
}