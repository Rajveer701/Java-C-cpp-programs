#include<iostream>
using namespace std;

class ArrayX{
    //Access specifier of Summation is private

    int Summation(int Arr[],int iSize){
    int iSum=0,iCnt=0;

    for(iCnt=0;iCnt<iSize;iCnt++){
        iSum += Arr[iCnt];
    }

        return iSum;
    }
};


int main(){
    int *Brr = NULL;
    int iLength=0,iCnt=0;

    ArrayX aobj;

    cout<<"Enter the number of elements"<<"\n";
    cin>>iLength;


    //c:  Brr = (int *)malloc(sizeof(int)* iLength);
    //java Brr = new int[iLength];

    Brr = new int[iLength];

    cout<<"Enter the elements"<<"\n";
    for(iCnt=0;iCnt<iLength;iCnt++){
       cin>>Brr[iCnt];
    }

    int iRet = 0;
    iRet = aobj.Summation(Brr,iLength);
    cout<<"Sum of the array elements is : "<<iRet<<endl;

    delete []Brr;

    return 0;
}