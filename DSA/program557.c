#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#pragma pack(1)

struct node{
    int data;
    struct node *lchild;
    struct node *rchild;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void Insert(PPNODE first,int iNo){
    PNODE newn = NULL;
    PNODE temp = NULL;
    
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->lchild = NULL;
    newn->rchild= NULL;

    if(*first == NULL){
        *first = newn;
    }
    else{
        temp = *first;

        while(1){
            if(iNo > temp->data){
                if(temp->rchild == NULL){
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }
            else if(iNo < temp->data){
                if(temp->lchild == NULL){
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;
            }
            else if(iNo == temp->data){
                printf("Unable to Insert as element is duplicate\n");
                free(newn);
                break;
            }
        }
        
    }
}

//L D R
void Inorder(PNODE first){
    if(first!=NULL){
        Inorder(first->lchild);
        printf("%d\n",first->data);
        Inorder(first->rchild);
    }
}

//D L R
void Preorder(PNODE first){
    if(first!=NULL){
        printf("%d\n",first->data);
        Preorder(first->lchild);
        Preorder(first->rchild);
    }
}

//L R D
void Postorder(PNODE first){
    
}


int main(){
    PNODE head = NULL;

    Insert(&head,11);
    Insert(&head,5);
    Insert(&head,17);

    printf("Inorder : \n");
    Inorder(head);

    printf("Preorder : \n");
    Preorder(head);

    printf("Postorder : \n");
    Postorder(head);
     
    return 0;
}