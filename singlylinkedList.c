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
        printf("| %d | -> ",first->data);
        first = first->next;
    }
    printf("NULL\n");
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

    if(NULL == *first){  //LL is empty 
        *first = newn;
    }
    else{              //LL contains atleast 1 node
        newn->next = *first;
        *first = newn;
    }
}

void InsertLast(PPNODE first,int iNo){
    PNODE newn = NULL;
    PNODE temp = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    if(NULL == *first){  //LL is empty 
        *first = newn;
    }
    else{              //LL contains atleast 1 node
        temp = *first;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newn;
    }
}

void InsertAtPos(PPNODE first,int iNo,int iPos){
    int iCount = 0;
    iCount = Count(*first);
    PNODE newn = NULL;
    PNODE temp = NULL;
    int i = 0;

    if( (iPos < 1) || (iPos > iCount) ){
        printf("Invalid Position");
        return;
    }

    if(iPos==1){
        InsertFirst(first,iNo);
    }
    else if(iPos == iCount){
        InsertLast(first,iNo);
    }
    else{
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = iNo;
        newn->next = NULL;

        temp = *first;

        for(i=1;i<iPos-1;i++){
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

void DeleteFirst(PPNODE first){
    PNODE temp = NULL;
    if(*first == NULL){                 //LL is empty
        return;
    }
    else if((*first)->next == NULL){    //LL contains only 1 node
        free(*first);
        *first = NULL;
    }
    else{                               //LL contains more than 1 node
        temp = *first;
        (*first) = (*first)->next;
        free(temp);
    }
}

void DeleteLast(PPNODE first){
    PNODE temp = NULL;
    if(*first == NULL){                 //LL is empty
        return;
    }
    else if((*first)->next == NULL){    //LL contains only 1 node
        free(*first);
        *first = NULL;
    }
    else{                               //LL contains more than 1 node
        temp = *first;
        while(temp->next->next != NULL){  //Type 3 while loop
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void DeleteAtPos(PPNODE first,int iPos){
    int iCount = 0;
    iCount = Count(*first);
    PNODE temp = NULL;
    PNODE target = NULL;
    int i = 0;

    if( (iPos < 1) || (iPos > iCount) ){
        printf("Invalid Position");
        return;
    }

    if(iPos==1){
        DeleteFirst(first);
    }
    else if(iPos == iCount){
        DeleteLast(first);
    }
    else{
        temp = *first;

        for(i=1;i<iPos-1;i++){
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        free(target);
    }
}

int main(){
    PNODE head = NULL;

    int iRet = 0;

    InsertFirst(&head,101);
    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    Display(head);

    iRet = Count(head);

    printf("Number of nodes : %d\n",iRet);

    InsertLast(&head,111);
    InsertLast(&head,121);

    Display(head);

    iRet = Count(head);

    printf("Number of nodes : %d\n",iRet);

    DeleteFirst(&head);

    Display(head);

    iRet = Count(head);

    printf("Number of nodes : %d\n",iRet);

    DeleteLast(&head);

    Display(head);

    iRet = Count(head);

    printf("Number of nodes : %d\n",iRet);

    InsertAtPos(&head,105,4);

    Display(head);

    iRet = Count(head);

    printf("Number of nodes : %d\n",iRet);

    DeleteAtPos(&head,5);

    Display(head);

    iRet = Count(head);

    printf("Number of nodes : %d\n",iRet);

    return 0;
}