// Strong Number
// Sum of factorials of individual digits = number itself
// 145
import java.io.*;

class program809{
    public static void main(String A[]) throws Exception
    {
        BufferedReader bobj = new BufferedReader(new InputStreamReader(System.in));

        int iNo = 0;
        long iFact = 0;
        int iTemp = 0;
        int iDigit = 0;
        long iSum = 0;

        iTemp = iNo;

        System.out.println("Enter number : ");
        iNo = Integer.parseInt(bobj.readLine());

        if(iNo<0){
            System.out.println("Invalid Number.I/p must be positive");
        }

        iFact = 1; 

        while(iNo!=0){
            iDigit = iNo%10; 
            while(iDigit != 0){
                iFact = iFact * iDigit;
                iDigit--;
            }
            iSum = iSum + iFact;
            iNo = iNo/10;
        }

        if(iSum == iTemp){
            System.out.println("Number is Strong Number");
        }
        else{
            System.out.println("Number is not a Strong Number");
        }
    }    
}
