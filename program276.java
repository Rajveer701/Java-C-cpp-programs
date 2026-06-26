import java.util.*;

public class program276{
    public static void main(String A[]){
        Scanner sobj = new Scanner(System.in);
        String data = null;
        int iRet = 0;

        StringX strobj = new StringX();   //Error

        System.out.println("Enter string : ");

        data = sobj.nextLine();

        iRet = strobj.CountCapital(data);

        System.out.println("Number of Capitals characters : "+iRet);

        iRet = strobj.CountSmall(data);

        System.out.println("Number of Small characters : "+iRet);

        iRet = strobj.CountDigits(data);

        System.out.println("Number of Digits : "+iRet);

        iRet = strobj.CountSpace(data);

        System.out.println("Number of white Spaces : "+iRet);

        iRet = strobj.CountSpecial(data);

        System.out.println("Number of Special Characters : "+iRet);
    }
}
