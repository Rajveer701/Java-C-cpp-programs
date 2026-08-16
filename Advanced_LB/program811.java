// Strong Number
// Sum of factorials of individual digits = number itself
// 145
import java.io.*;

class program811{
    public static void main(String A[]) throws Exception
    {
        BufferedReader bobj = new BufferedReader(new InputStreamReader(System.in));

        int iFact[] = {1,1,2,6,24,120,720,5040,40320,362880};
        int iNo = 0;
        int iTemp = 0;
        int iDigit = 0;
        long iSum = 0;

        System.out.println("Enter number : ");
        iNo = Integer.parseInt(bobj.readLine());

        if(iNo<0){
            System.out.println("Invalid Number.I/p must be positive");
        }

        iTemp = iNo;

        while(iNo!=0){
            iDigit = iNo%10; 
            iSum = iSum + iFact[iDigit];
            iNo = iNo/10;

            if(iSum > iTemp){
                break;
            }
        }

        if(iSum == iTemp){
            System.out.println("Number is a Strong Number");
        }
        else{
            System.out.println("Number is not a Strong Number");
        }
    }    
}
