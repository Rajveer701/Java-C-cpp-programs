// Automorphic Number
// Number whose square ends with the exact same digits as that of the number
// 5 : 5*5 = 25 --> 5==5
// 25 : 625 
// 376 : 141376

import java.io.*;

class program827{
    public static void main(String A[]) throws Exception
    {
        BufferedReader bobj = new BufferedReader(new InputStreamReader(System.in));

        int iNo = 0;
        int iTemp = 0;
        int iSquare = 0;
        int iCount = 0;
        int iDen = 0;

        System.out.println("Enter number to check if Harshad Number or not : ");
        iNo = Integer.parseInt(bobj.readLine());

        iTemp = iNo;

        iSquare = iNo*iNo;

        while(iNo!=0){
            iCount++;
            iNo = iNo/10;
        }

        iDen = (int)Math.pow(10, iCount);

        if(iSquare%iDen == iTemp){
            System.out.println("Number is Automorphic");
        }
        else{
            System.out.println("Number is not Automorphic");
        }
    }  
}
