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

void Display(PNODE first,PNODE last){
    if( first==NULL && last==NULL){
        return;
    }
    do{
        printf("| %d | -> ",first->data);
        first = first->next;
    }while(first!=last->next);

    printf("\n");
}

int Count(PNODE first,PNODE last){
    int iCount = 0;
    if( first==NULL && last==NULL){
        return 0;
    }
    do{
        iCount++;
        first = first->next;
    }while(first!=last->next);

    return iCount;
}

void InsertFirst(PPNODE first,PPNODE last,int iNo){
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = iNo;
    newn->next = NULL;

    if(NULL == *first && NULL == *last){
        *first = newn;
        *last = newn; 
    }
    else{
        newn->next = *first;
        *first = newn;
    }
    (*last)->next = *first;     //imp
}

void InsertLast(PPNODE first,PPNODE last,int iNo){
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = iNo;
    newn->next = NULL;

    if(NULL == *first && NULL == *last){
        *first = newn;
        *last = newn; 
    }
    else{
        (*last)->next = newn;
        *last = (*last)->next;  //*last = newn
    }
    (*last)->next = *first;     //imp
}

void InsertAtPos(PPNODE first,PPNODE last,int iNo,int iPos){

}

void DeleteFirst(PPNODE first,PPNODE last){
    if(NULL == *first && NULL == *last){
        printf("LL is empty\n");
        return;
    }
    else if(*first == *last){
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else{
        *first = (*first)->next;
        free((*last)->next);
        (*last)->next = *first;  //imp
    }
}

void DeleteLast(PPNODE first,PPNODE last){
    if(NULL == *first && NULL == *last){
        printf("LL is empty\n");
        return;
    }
    else if(*first == *last){
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else{
        
    }
}

void DeleteAtPos(PPNODE first,PPNODE last,int iPos){
    
}

int main(){
    PNODE head = NULL;
    PNODE tail = NULL;
    int iRet = 0;

    InsertFirst(&head,&tail,51);
    InsertFirst(&head,&tail,21);
    InsertFirst(&head,&tail,11);

    InsertLast(&head,&tail,101);
    InsertLast(&head,&tail,111);
    InsertLast(&head,&tail,121);

    Display(head,tail);

    iRet = Count(head,tail);

    printf("No. of elements : %d\n",iRet);

    DeleteFirst(&head,&tail);

     Display(head,tail);

    iRet = Count(head,tail);

    printf("No. of elements : %d\n",iRet);

    return 0;
}    