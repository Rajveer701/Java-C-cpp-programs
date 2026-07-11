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
    PNODE temp = NULL;
    PNODE newn = NULL;
    int i = 0;

    if((iPos<1) && (iPos>iCount+1)){
        printf("Invalid Position");
        return;
    }

    if(iPos == 1){
        InsertFirst(iNo);
    }
    else if(iPos == iCount+1){
        InsertLast(iNo);
    }
    else{
        temp = first;

        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = iNo;
        newn->next = NULL;

        for(i=1;i<iPos-1;i++){
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        this->iCount++;
    }

}

void singlyCL::DeleteFirst(){
    PNODE temp = NULL;
    if(NULL == first && NULL == last){
        cout<<"LL is empty"<<endl;
        return;
    }
    else if(this->first->next == NULL){
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else{
        temp = this->first;
        this->first = this->first->next;
        delete temp;
    }
    this->iCount--;
}

void singlyCL::DeleteLast(){
    PNODE temp = NULL;
    if(NULL == first && NULL == last){
        printf("LL is empty\n");
        return;
    }
    else if(first == last){
        delete first;
        first = NULL;
        last = NULL;
    }
    else{
        temp = first;
        while(temp->next != last){
            temp = temp->next;
        }
        delete last;
        last= temp;
        last->next = first;
    }
}

void singlyCL::DeleteAtPos(int iPos){
    PNODE temp = NULL;
    PNODE target = NULL;
    int i = 0;

    if((iPos<1) && (iPos>iCount)){
        printf("Invalid Position");
        return;
    }

    if(iPos == 1){
        DeleteFirst();
    }
    else if(iPos == iCount){
        DeleteLast();
    }
    else{
        temp = first;

        for(i=1;i<iPos-1;i++){
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        delete target;
        this->iCount--;
    }
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

    sobj.DeleteFirst();
    sobj.DeleteLast();

    sobj.Display();

    iRet = sobj.Count();
    cout<<"No. of elements : "<<iRet<<endl;

    sobj.InsertAtPos(105,3);

    sobj.Display();

    iRet = sobj.Count();
    cout<<"No. of elements : "<<iRet<<endl;

    sobj.DeleteAtPos(3);

    sobj.Display();

    iRet = sobj.Count();
    cout<<"No. of elements : "<<iRet<<endl;

    return 0;
}