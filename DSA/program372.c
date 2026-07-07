#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)

struct node{
    int data;
    struct node *next; 
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void Display(PNODE first){
    while(first!=NULL){
        printf("%d\t",first->data);
        first = first->next;
    }
    printf("\n");
}

int Count(PNODE first){
    int iCount = 0;
    while(first!=NULL){
        iCount++;
        first = first->next;
    }
    return iCount;
}

void InsertFirst(PPNODE first,int iNo){
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    if(*first==NULL){  //LL is empty 
        *first = newn;
    }
    else{              //LL contains atleast 1 node
        newn->next = *first;
        *first = newn;
    }
}

void InsertLast(PPNODE first,int iNo){
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    if(*first==NULL){  //LL is empty 
        *first = newn;
    }
    else{              //LL contains atleast 1 node
        
    }
}

void InsertAtLPos(PPNODE first,int iNo,int iPos){

}

void DeleteFirst(PPNODE first){

}

void DeleteLast(PPNODE first){

}

void DeleteAtLPos(PPNODE first,int iPos){

}

int main(){
    PNODE head = NULL;

    InsertFirst(&head,101);
    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    Display(head);

    return 0;
}