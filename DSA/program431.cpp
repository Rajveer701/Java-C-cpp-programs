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
    int iChoice = 0;
    int iValue = 0;
    int iRet = 0;
    int iPosition = 0;

    while(iChoice!=9){  
        cout<<"--------------------\n";
        cout<<"Enter your choice : \n";
        cout<<"--------------------\n";
        cout<<"1 : Insert node at first position\n";
        cout<<"2 : Insert node at last position\n";
        cout<<"3 : Insert node at given position\n";
        cout<<"4 : Delete node at first position\n";
        cout<<"5 : Delete node at last position\n";
        cout<<"6 : Delete node at given position\n";
        cout<<"7 : Display the elements \n";
        cout<<"8 : Count the number of elements \n";
        cout<<"9 : Terminate the application\n";
        cout<<"--------------------\n";
        cin>>iChoice;

        switch(iChoice){
            case 1 : 
                cout<<"Enter the value\n";
                cin>>iValue;
                sobj.InsertFirst(iValue);
                break;
            case 2 : 
                cout<<"Enter the value\n";
                cin>>iValue;
                sobj.InsertLast(iValue);
                break;
            case 3 : 
                cout<<"Enter the value\n";
                cin>>iValue;
                cout<<"Enter the position\n";
                cin>>iPosition;
                sobj.InsertAtPos(iValue,iPosition);
                break;
            case 4 : 
                sobj.DeleteFirst();
                break;
            case 5 : 
                sobj.DeleteLast();
                break;
            case 6 : 
                cout<<"Enter the position\n";
                cin>>iPosition;
                sobj.DeleteAtPos(iPosition);
                break;
            case 7 : 
                cout<<"Elements of the LL are : \n";
                sobj.Display();
                break;
            case 8 : 
                iRet = sobj.Count();
                cout<<"Number of elements : "<<iRet<<endl;
                break;
            case 9 :
                cout<<"Thank you for using\n";
                break;
            default:
                cout<<"Invalid choice\n";
        }
    }

    return 0;
}