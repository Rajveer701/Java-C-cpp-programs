#include<iostream>
using namespace std;

#pragma pack(1)

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

typedef struct node NODE;
typedef struct node* PNODE;

class DoublyCL{
    private:
        PNODE first;
        PNODE last;
        int iCount = 0;
    public:
        DoublyCL();
        
        void Display();
        int Count();

        void InsertFirst(int iNo);
        void InsertLast(int iNo);
        void InsertAtPos(int iNo,int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

DoublyCL::DoublyCL(){
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

int DoublyCL::Count(){
    return 0;
}


int main(){
    DoublyCL dobj;

    cout<<sizeof(dobj)<<endl;

    return 0;
}