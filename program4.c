#include<stdio.h> //standard i/p o/p

int main()
{
    int i,j,k;    //local var
    
    printf("Enter first number : \n");
    scanf("%d",&i);

    printf("Enter second number : \n");
    scanf("%d",&j);

    k = i + j;
    printf("Additon is : %d\n",k);

    return 0;
}