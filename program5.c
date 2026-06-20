 /*
    Algorithm

    START
        Accept first number as no1
        Accept second number as no2
        Perform Addition of no1 & no2
        Display the result
    STOP
 */


#include<stdio.h> 

int main()
{
    float i,j,k;

    printf("Enter 1st number : \n");
    scanf("%f",&i);

    printf("Enter 2nd number : \n");
    scanf("%f",&j);

    k = i + j;
    printf("Additon is : %f\n",k);

    return 0;
}