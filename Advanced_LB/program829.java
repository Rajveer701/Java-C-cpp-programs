import java.io.*;

class program829{
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
            if(iNo%10 != iSquare%10){
                break;
            }
            else{
                iNo = iNo/10;
                iSquare = iSquare/10;
            }
        }
        if(iNo == 0){
            System.out.println("It is Automorphic");
        }
        else{
            System.out.println("It is not Automorphic");
        }
    }  
}
