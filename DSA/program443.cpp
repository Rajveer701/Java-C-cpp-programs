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
    return iCount;
}

void DoublyCL::Display(){
    PNODE temp = NULL;
    if(first == NULL && last == NULL){
        return;
    }
    temp = first;
    do{
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }while(last->next != temp);
    cout<<"\n";
}

void DoublyCL::InsertFirst(int iNo){
    PNODE newn = NULL;
    newn = new NODE();
    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL){
        first = newn;
        last = newn;
    }
    else{
        
    }
}

void DoublyCL::InsertLast(int iNo){
    
}

void DoublyCL::InsertAtPos(int iNo,int iPos){
    
}

void DoublyCL::DeleteFirst(){
    
}

void DoublyCL::DeleteLast(){
    
}

void DoublyCL::DeleteAtPos(int iPos){
    
}


int main(){
    DoublyCL dobj;

    

    return 0;
}