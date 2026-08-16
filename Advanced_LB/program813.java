// Armstrong Number
// Sum of its individual digits raised to its total number of digits = number itself
// 153 = 1^3 + 5^3 + 3^3 = 1+125+27 = 153

// x = 3 , y = 5
// 3*3*3*3*3
import java.io.*;

class program813{
    public static void main(String A[]) throws Exception
    {
        BufferedReader bobj = new BufferedReader(new InputStreamReader(System.in));

        int x = 0;
        int y = 0;

        int iPower = 0;

        System.out.println("Enter number as a base : ");
        x = Integer.parseInt(bobj.readLine());

        System.out.println("Enter number as a power : ");
        y = Integer.parseInt(bobj.readLine());

        iPower = 1;

        while(y!=0){
            iPower = iPower*x;
            y--;
        }

        System.out.println("Result : "+iPower);
    }    
}
