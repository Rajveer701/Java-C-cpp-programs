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

class SinglyLL{
    public:
        PNODE first;
        int iCount;

        SinglyLL(){
            cout<<"Inside Constructor"<<endl;
            this->first = NULL;
            this->iCount = 0;
        }
};

int main(){
    SinglyLL sobj;

    // 5 nodes

    sobj.first = NULL;  // Drawback due to public access specifier
    sobj.iCount = 15;   // Drawback due to public access specifier
    
    return 0;
}