#include<iostream>
using namespace std;

template <class T>
class ArrayX{
    public:
        int *Arr;
        int Size;

        ArrayX(int No);
        ~ArrayX();
        void Accept();
        void Display();
        T Summation();
};

template <class T>
ArrayX<T>::ArrayX(int No){
    Size = No;
    Arr = new T(Size);
}

template <class T>
ArrayX<T>::~ArrayX(){
    delete []Arr;
}

template <class T>
void ArrayX<T>::Accept(){
    int i = 0;
    cout<<"Enter the elements : \n";

    for(i=0;i<Size;i++){
        cin>>Arr[i];
    }
}

template <class T>
void ArrayX<T>::Display(){
    int i = 0;
    cout<<"Elements of the array are : \n";

    for(i=0;i<Size;i++){
        cout<<Arr[i]<<"\n";
    }
}

template <class T>
T ArrayX<T>::Summation(){
    int i = 0;
    int sum = 0;

    for(i=0;i<Size;i++){
        sum = sum + Arr[i];
    }
    return sum;
}


int main(){
    ArrayX <int>aobj(5);

    aobj.Accept();
    aobj.Display();
    cout<<aobj.Summation()<<"\n";
    
    return 0;
}