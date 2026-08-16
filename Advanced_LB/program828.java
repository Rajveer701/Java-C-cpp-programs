// Automorphic Number
// Number whose square ends with the exact same digits as that of the number
// 5 : 5*5 = 25 --> 5==5
// 25 : 625 
// 376 : 141376

import java.io.*;

class program828{
    public static void main(String A[]) throws Exception
    {
        BufferedReader bobj = new BufferedReader(new InputStreamReader(System.in));

        int iNo = 0;
        int iSquare = 0;
        int iCount = 0;

        System.out.println("Enter number to check if Harshad Number or not : ");
        iNo = Integer.parseInt(bobj.readLine());

        String strNo = String.valueOf(iNo);

        iCount = strNo.length();

        iSquare = iNo*iNo;

        String strSquare = String.valueOf(iSquare);

        if(strSquare.endsWith(strNo)){
            System.out.println("It is Automorphic");
        }
        else{
            System.out.println("It is not Automorphic");
        }
    }  
}
