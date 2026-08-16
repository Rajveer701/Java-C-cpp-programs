// Harshad Number
// Num can be divided completely by the sum of its digits
// 18 --> 1+8 = 9   --> 18 % 9 = 0

import java.io.*;


class program820{
    public static void main(String A[]) throws Exception
    {
        BufferedReader bobj = new BufferedReader(new InputStreamReader(System.in));

        int i = 0;
        int iNo = 0;
        int iSum = 0;
        int iDigit = 0;
        int iTemp = 0;
        int iStart = 0;
        int iEnd = 0;

        System.out.println("Enter the starting point : ");
        iStart = Integer.parseInt(bobj.readLine());

        System.out.println("Enter the ending point : ");
        iEnd = Integer.parseInt(bobj.readLine());

        System.out.println("Harshad Numbers are : ");
        for(i=iStart;i<=iEnd;i++){
            iNo = i;

            while(iNo!=0){
                iDigit = iNo%10;
                iSum = iSum+iDigit;
                iNo = iNo/10;
            }
            if(i%iSum == 0){
                System.out.println(i);
            }
            iSum = 0;
        }

    }  
}
