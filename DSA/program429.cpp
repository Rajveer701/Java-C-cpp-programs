#include<iostream>
using namespace std;

#pragma pack(1)

struct node{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;

class singlyCL{
    private:
        PNODE first;
        PNODE last;
        int iCount = 0;
    public:
        singlyCL();
        
        void Display();
        int Count();

        void InsertFirst(int iNo);
        void InsertLast(int iNo);
        void InsertAtPos(int iNo,int iPos);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

singlyCL::singlyCL(){
    cout<<"Inside Constructor\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

void singlyCL::Display(){
    
}

int singlyCL::Count(){
    return 0;
}

void singlyCL::InsertFirst(int iNo){
    
}

void singlyCL::InsertLast(int iNo){
    
}

void singlyCL::InsertAtPos(int iNo,int iPos){
    
}

void singlyCL::DeleteFirst(){
    
}

void singlyCL::DeleteLast(){
    
}

void singlyCL::DeleteAtPos(int iPos){

}

int main(){
    singlyCL sobj;

    return 0;
}