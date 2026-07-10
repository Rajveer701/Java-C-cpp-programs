#include<iostream>
using namespace std;

#pragma pack(1)

struct node{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

int main(){
    PNODE newn = NULL;

    // c --> newn = (PNODE)malloc(sizeof(NODE));
    newn = new NODE;
    newn->data = 11;
    newn->next = NULL;

    cout<<newn->data<<endl;

    //free(newn);
    delete newn;

    cout<<newn->data<<endl;

    return 0;
}