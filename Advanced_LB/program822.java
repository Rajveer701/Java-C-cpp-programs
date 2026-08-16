// Palindrome Number
// 1221,11,102201

import java.io.*;

class program822{
    public static void main(String A[]) throws Exception
    {
        BufferedReader bobj = new BufferedReader(new InputStreamReader(System.in));

        int iNo = 0;
        int iDigit = 0;
        int iTemp = 0;
        int iRev = 0;

        System.out.println("Enter number to check if Harshad Number or not : ");
        iNo = Integer.parseInt(bobj.readLine());

        iTemp = iNo;

        while(iNo!=0){
            iDigit = iNo%10;
            iRev = (iRev*10)+iDigit;
            iNo = iNo/10;
        }

        System.out.println("Reversed number : "+iRev);

        if(iTemp == iRev){
            System.out.println("It is a Palindrome Number");
        }
        else{
            System.out.println("It is not a Palindrome Number");
        }

    }  
}
