#include<stdio.h> 

float AddTwoNumbers(
                        float fNo1,                         //first ip         
                        float fNo2                          //second ip
                    )
{
    float fAns = 0.0f;                                      //Variable to store result
    fAns = fNo1 + fNo2;                                     //perform Addition

    return fAns;
}

int main()
{   
    float fValue1 = 0.0f;                                   //To store first input
    float fValue2 = 0.0f;                                   //To store second input
    float fResult = 0.0f;                                   //To store the result

    printf("Enter 1st number : \n");
    scanf("%f",&fValue1);

    printf("Enter 2nd number : \n");
    scanf("%f",&fValue2);

    fResult =  AddTwoNumbers(fValue1,fValue2);               //Call func
    printf("Additon is : %f\n",fResult);

    return 0;
}
