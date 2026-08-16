import java.io.*;

class program804{
    public static void main(String A[]) throws Exception
    {
        BufferedReader bobj = new BufferedReader(new InputStreamReader(System.in));

        int iNo = 0;
        int sum = 0;
        int iDigit = 0;
        int iTemp = 0;
        System.out.println("Enter number : ");
        iNo = Integer.parseInt(bobj.readLine());

        if(iNo<0){
            System.out.println("Invalid Number.I/p must be positive");
        }

        iTemp = iNo;

        while(iNo!=0){
            iDigit = iNo%10;
            iNo = iNo/10;
        }

        System.out.println("Original number is : " + iTemp);
    }    
}
