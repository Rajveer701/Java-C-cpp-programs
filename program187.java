// i/p : 7
// o/p : A b C d E f G
//       1 2 3 4 5 6 7 
import java.util.*;

class program187{
    public static void Display(int iNo){
        //Logic
        int iCnt=0;
        char chCap = '\0';
        char chSmall = '\0';
        for(iCnt=1,chCap='A',chSmall='a';iCnt<=iNo;iCnt++,chCap++,chSmall++){
            if(iCnt%2==0){
                System.out.print(chSmall + "\t");
            }
            else{
                System.out.print(chCap+"\t");
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