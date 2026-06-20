//check prime number

import java.util.Scanner;

class NumberX
{
    public boolean CheckPrime(int iNo)
    {
        // Logic
        int iCnt = 0;
        boolean bFlag = true;
       for(iCnt=2;iCnt<=(iNo/2);iCnt++)
       {
        if((iNo%iCnt) == 0)
        {
            bFlag = false;
            break;
        }
       }
       return bFlag;
    }
}

class program68
{
    public static void main(String A[])
    {
        Scanner sobj = new Scanner(System.in);

        int iValue = 0;
        boolean bRet = false;
        
        System.out.println("Enter number : ");
        iValue = sobj.nextInt();

        NumberX nobj = new NumberX();     

        bRet = nobj.CheckPrime(iValue);
        if(bRet == true){
            System.out.println("Number is prime");
        }
        else{
            System.out.println("Number is not prime");
        }
    }
}



/*

000101110001
110011000011
000101110001     --> return false;
110011000011
110011000011      dump lines
110011000011
000101110001
000101110001

*/