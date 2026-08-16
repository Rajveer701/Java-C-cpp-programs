// Harshad Number
// Num can be divided completely by the sum of its digits
// 18 --> 1+8 = 9   --> 18%9=0

import java.io.*;


class program818{
    public static void main(String A[]) throws Exception
    {
        BufferedReader bobj = new BufferedReader(new InputStreamReader(System.in));

        int iNo = 0;
        int iSum = 0;
        int iDigit = 0;
        int iTemp = 0;

        System.out.println("Enter number to check if Harshad Number or not : ");
        iNo = Integer.parseInt(bobj.readLine());

        iTemp = iNo;

        while(iNo!=0){
            iDigit = iNo%10;
            iSum = iSum+iDigit;
            iNo = iNo/10;
        }


        if(iTemp%iSum == 0){
            System.out.println("It is a Harshad Number");
        }
        else{
            System.out.println("It is not a Harshad Number");
        }
    }  
}
