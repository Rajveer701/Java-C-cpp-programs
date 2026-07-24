#include<iostream>
using namespace std;

#pragma pack(1)

class Searching{
    private:
        int *Arr;
        int iSize;
    public:
        Searching(int iNo);
        ~Searching();
        void Accept();
        void Display();
        bool LinearSearch(int iNo);
        bool BiDirectionalSearch(int iNo);
};

Searching::Searching(int iNo){
    iSize = iNo;
    Arr = new int[iSize];
}

Searching:: ~Searching(){
    delete []Arr;
}

void Searching::Accept(){
    int i = 0;
    cout<<"Enter the elements : \n";

    for(i=0;i<iSize;i++){
        cin>>Arr[i];
    }
}

void Searching::Display(){
    int i = 0;
    cout<<"Elements of the array are : \n";

    for(i=0;i<iSize;i++){
        cout<<Arr[i]<<"\n";
    }
}

//TC worst case O(N)
bool Searching::LinearSearch(int iNo){
    bool bFlag = false;
    int i = 0;

    for(i=0;i<iSize;i++){
        if(Arr[i]==iNo){
            bFlag = true;
            break;
        }
    }
    return bFlag;
}


//TC worst case O(N/2)
bool Searching::BiDirectionalSearch(int iNo){
    bool bFlag = false;
    int iStart = 0,iEnd = 0;

    iStart = 0;
    iEnd = iSize-1;

    while(iEnd>iStart){         //Wrong condition middle ele issue
        if(Arr[iStart] == iNo || Arr[iEnd] == iNo){
            bFlag = true;
            break;
        }
        iStart++;
        iEnd--;
    }
    return bFlag;
}

int main(){
    Searching sobj(5);

    sobj.Accept();
    sobj.Display();

    if(sobj.LinearSearch(30)==true){
        cout<<"Element is present"<<endl;
    }
    else{
        cout<<"Element is not present"<<endl;
    }

    if(sobj.BiDirectionalSearch(30)==true){
        cout<<"Element is present"<<endl;
    }
    else{
        cout<<"Element is not present"<<endl;
    }

    return 0;
}