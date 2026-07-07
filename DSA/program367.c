#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)

struct node{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node * * PPNODE;

void InsertAtFirst(PPNODE first,int no){
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE)); 

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL){
        *first = newn;
    }
    else{
        newn -> next = *first;
        *first = newn;
    }
}

void InsertAtLast(PPNODE first,int no){
    PNODE newn = NULL;
    PNODE temp = NULL;
    newn = (PNODE)malloc(sizeof(NODE)); 

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL){
        *first = newn;
    }
    else{
        temp = *first;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp -> next = newn;
    }
}

void DeleteFirst(PPNODE first){
    PNODE temp = NULL;
    if(*first == NULL){
        printf("List is empty\n");
        return;
    }
    else if((*first)->next==NULL){
        free(*first);
        *first = NULL;
    }
    else{
        temp = *first;
        *first = (*first)->next;
        free(temp);
    }
}

void DeleteLast(PPNODE first){
    PNODE temp = NULL;
    if(*first == NULL){
        printf("List is empty\n");
        return;
    }
    else if((*first)->next==NULL){
        free(*first);
        *first = NULL;
    }
    else{
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void InsertAtPos(PPNODE first, int no, int pos){
    PNODE newn = NULL;
    PNODE temp = NULL;

    int iCnt = 0;
    int iSize = 0;
    iSize = Count(*first);

    if((pos < 1) || (pos > iSize + 1))      {
        printf("Invalid position\n");
        return;
    }

    if(pos == 1){
        InsertAtFirst(first,no);
    }
    else if(pos == iSize+1){
        InsertAtLast(first,no);
    }
    else{
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;

        temp = *first;

        for(iCnt = 1; iCnt < pos-1; iCnt++){
            temp = temp ->next;
        }

        newn->next = temp->next;    
        temp->next = newn;          
    }
}

void DeleteAtPos(PPNODE first, int pos){
    int iSize = 0;
    int iCnt = 0;

    PNODE temp = NULL;
    PNODE target = NULL;

    iSize = Count(*first);

    if((pos < 1) || (pos > iSize))      {
        printf("Invalid position\n");
        return;
    }

    if(pos == 1){
        DeleteFirst(first);
    }
    else if(pos == iSize){
        DeleteLast(first);
    }
    else{
        temp = *first;

        for(iCnt = 1; iCnt < pos-1; iCnt++){
            temp = temp -> next;
        }

        target = temp->next;

        temp->next = target -> next;        
        free(target);                       
    }
}

void Display(PNODE first){
    PNODE temp = NULL;
    temp = first;

    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}

int Count(PNODE first){
    PNODE temp = NULL;
    temp = first;
    int iCount = 0;

    while(temp!=NULL){
        iCount++;
        temp = temp->next;
    }
    return iCount;
}

int main(){
    PNODE head = NULL;
    int iRet = 0;

    InsertAtFirst(&head,51);
    InsertAtFirst(&head,21);
    InsertAtFirst(&head,11);
    
    Display(head);
    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);

    InsertAtLast(&head,101);
    InsertAtLast(&head,111);
    InsertAtLast(&head,121);
    
    Display(head);
    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);

    DeleteFirst(&head);

    Display(head);
    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);

    DeleteLast(&head);

    Display(head);
    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);

    InsertAtPos(&head,105,3);

    Display(head);
    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);
    
    DeleteAtPos(&head,3);

    Display(head);
    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);
    
    return 0;
}