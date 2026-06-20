//Check whether number is perfect or not ie. summation of factors is equal to num itself ex. 6 = 1+2+3

import java.util.Scanner;

class NumberX
{
    public boolean CheckPerfect(int iNo)
    {
        // Logic
        int iCnt = 0;
        int iSum = 0;
       for(iCnt=(iNo/2);iCnt>=1;iCnt--)
       {
        if((iNo%iCnt) == 0)
        {
            iSum = iSum + iCnt;
        }
        if(iSum>iNo){
            break;
        }
       }
       if(iSum == iNo){
        return true;
       }
       else{
        return false;
       }
    }
}

class program52
{
    public static void main(String A[])
    {
        Scanner sobj = new Scanner(System.in);

        int iValue = 0;
        boolean bRet = false;
        
        System.out.println("Enter number : ");
        iValue = sobj.nextInt();

        NumberX nobj = new NumberX();     

        bRet = nobj.CheckPerfect(iValue);
        if(bRet == true){
            System.out.println("Number is perfect");
        }
        else{
            System.out.println("Number is not perfect");
        }
    }
}

