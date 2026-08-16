// 5!
// 5 * 4 * 3 * 2 * 1
import java.io.*;

class program807{
    public static void main(String A[]) throws Exception
    {
        BufferedReader bobj = new BufferedReader(new InputStreamReader(System.in));

        int iNo = 0;
        int iFact = 0;

        System.out.println("Enter number : ");
        iNo = Integer.parseInt(bobj.readLine());

        if(iNo<0){
            System.out.println("Invalid Number.I/p must be positive");
        }

        iFact = 1; 

        while(iNo!=0){
            iFact = iFact*iNo;
            iNo--;
        }

        System.out.println("Factorial is : " + iFact);
    }    
}
