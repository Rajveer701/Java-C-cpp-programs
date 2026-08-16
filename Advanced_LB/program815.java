// Armstrong Number
// Sum of its individual digits raised to its total number of digits = number itself
// 153 = 1^3 + 5^3 + 3^3 = 1+125+27 = 153

// x = 3 , y = 5
// 3*3*3*3*3
import java.io.*;


class program815{
    public static void main(String A[]) throws Exception
    {
        BufferedReader bobj = new BufferedReader(new InputStreamReader(System.in));

        int iNo = 0;
        int iTemp = 0;
        int iCount = 0;
        int iSum = 0;

        System.out.println("Enter number to check if Armstrong : ");
        iNo = Integer.parseInt(bobj.readLine());

        iTemp = iNo;

        while(iNo!=0){
            iCount++;
            iNo=iNo/10;
        }

        System.out.println("Number of digits : " +iCount);

    }  
}
