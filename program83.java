import java.util.*;

class DigitX{
    public int CountDigits(int iNo){
        //Logic
        int iCount = 0;
        //int iDigit = 0; 
        while(iNo!=0){
            //iDigit = iNo%10;
            iCount = iCount + 1;
            iNo = iNo/10; 
        }
        return iCount;
    }
}

class program83{
    public static void main(String A[]){
        Scanner sobj = new Scanner(System.in);
        DigitX dobj = new DigitX();

        int iValue = 0;
        int iRet = 0;

        System.out.println("Enter Number : ");
        iValue = sobj.nextInt();

        iRet = dobj.CountDigits(iValue);

        System.out.println("Number of digits is : "+iRet);
    }
}