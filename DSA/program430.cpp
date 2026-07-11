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
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

void singlyCL::Display(){
    PNODE temp = NULL;
    if(first == NULL && last == NULL){
        return;
    }
    temp = first;
    do{
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    }while(last->next != temp);
    cout<<"\n";
}

int singlyCL::Count(){
    return this->iCount;
}

void singlyCL::InsertFirst(int iNo){
    PNODE newn = NULL;
    newn = new NODE;
    newn->data = iNo;
    newn->next = NULL;

    if(first == NULL && last == NULL){
        first = newn;
        last = newn; 
    }
    else{
        newn->next = first;
        first = newn;
        last->next = first;
    }
    iCount++;
}

void singlyCL::InsertLast(int iNo){
     PNODE newn = NULL;
    newn = new NODE;
    newn->data = iNo;
    newn->next = NULL;

    if(first == NULL && last == NULL){
        first = newn;
        last = newn; 
    }
    else{
       last->next = newn;
       last = newn;
       last->next = first;
    }
    iCount++;
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
    int iRet = 0;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(121);

    sobj.Display();

    iRet = sobj.Count();
    cout<<"No. of elements : "<<iRet<<endl;

    return 0;
}