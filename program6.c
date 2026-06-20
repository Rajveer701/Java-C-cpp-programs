 /*
    Algorithm

    START
        Accept first number as no1
        Accept second number as no2
        Perform Addition of no1 & no2
        Display the result
    STOP
 */

//default value
//char \0 
//int 0
//float/decimal 0.0

#include<stdio.h> 

int main()
{   
    //variable creation with default values
    float i=0.0f, j=0.0f, k=0.0f;        

    printf("Enter 1st number : \n");
    scanf("%f",&i);

    printf("Enter 2nd number : \n");
    scanf("%f",&j);

    k = i + j;
    printf("Additon is : %f\n",k);

    return 0;
}


//int iMarks = 0;
//int iAge = 0;  i --> datatype
//float fVal1 = 0.0f;