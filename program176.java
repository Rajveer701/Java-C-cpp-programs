// i/p : 7
// o/p : 1 * 3 * 5 * 7
import java.util.*;

class program176{
    public static void Display(int iNo){
        //Logic
        int iCnt=0;
        for(iCnt=1;iCnt<=iNo;iCnt++){
            if(iCnt%2==0){
                System.out.print("*\t");
            }
            else{
                System.out.print(iCnt+"\t");
            }
        }
        System.out.println();
    }

    public static void main(String A[]){
        Scanner sobj = new Scanner(System.in);
        int iValue = 0;

        System.out.println("Enter the number of elements :");
        iValue = sobj.nextInt();

        Display(iValue);
         
    }
}