#include<stdio.h>

#pragma pack(1)

struct node{
    int data;
    struct node *next;
};

typedef struct node NODE; 
typedef struct node * PNODE; 

void Display(PNODE first){
    PNODE temp = NULL;
    temp = first;
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}

int Count(PNODE first){
    int iCount = 0;
    PNODE temp = NULL;
    temp = first;
    while(temp!=NULL){
        iCount++;
        temp = temp->next;
    }
    return iCount;
}

int main(){
    PNODE head = NULL;
    NODE obj1,obj2,obj3;
    int iRet = 0;

    head = &obj1;

    obj1.data = 11;
    obj1.next = &obj2;

    obj2.data = 21;
    obj2.next = &obj3;

    obj3.data = 51;
    obj3.next = NULL;

    Display(head);
    iRet = Count(head);      //Count(Address of head)

    printf("Number of nodes : %d\n",iRet);

    return 0;
}