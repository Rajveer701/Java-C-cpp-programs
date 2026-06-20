// i/p : 11
// o/p : * * * # # # * * * # # 
//       1 2 3 4 5 6 7 8 9 10 11
import java.util.*;

class program188{
    public static void Display(int iNo){
        //Logic
        int iCnt=0;
        int iVar1=0;
        int iVar2=0;
        for(iCnt=1,iVar1=1,iVar2=1;iCnt<=iNo;iCnt++){
            if(iVar1<=3){
                System.out.print("*\t");
                iVar1++;
                iVar2--;
            }
            else if(iVar2>0){
                System.out.print("#\t");
                iVar2++;
                iVar1--;
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