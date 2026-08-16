// Armstrong Number
// Sum of its individual digits raised to its total number of digits = number itself
// 153 = 1^3 + 5^3 + 3^3 = 1+125+27 = 153

import java.io.*;


class program817{
    public static void main(String A[]) throws Exception
    {
        BufferedReader bobj = new BufferedReader(new InputStreamReader(System.in));

        int iNo = 0;
        int iTemp = 0;
        int iCount = 0;
        int iSum = 0;
        int iDigit = 0;

        System.out.println("Enter number to check if Armstrong : ");
        iNo = Integer.parseInt(bobj.readLine());

        iTemp = iNo;

        while(iNo!=0){
            iCount++;
            iNo=iNo/10;
        }

        iNo = iTemp;

        while(iNo!=0){
            iDigit = iNo%10;
            iSum = iSum + (int)Math.pow(iDigit, iCount);
            iNo = iNo/10;
        }

        if(iSum == iTemp){
            System.out.println("Number is Armstrong");
        }
        else{
            System.out.println("Number is not Armstrong");
        }

    }  
}
