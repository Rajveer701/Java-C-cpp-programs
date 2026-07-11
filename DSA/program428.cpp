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
};

singlyCL::singlyCL(){
    cout<<"Inside Constructor\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

int main(){
    singlyCL sobj;

    return 0;
}