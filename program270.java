import java.util.*;

class StringX{
    public int CountCapital(String str){
        int iCount = 0;
        int i = 0;

        for(i=0;i<str.length();i++){
            if(str.charAt(i)>='A' && str.charAt(i)<='Z'){
                iCount++;
            }
        }

        return iCount;
    }
}

public class program270{
    public static void main(String A[]){
        Scanner sobj = new Scanner(System.in);
        String data = null;
        int iRet = 0;

        StringX strobj = new StringX();

        System.out.println("Enter string : ");

        data = sobj.nextLine();

        iRet = strobj.CountCapital(data);

        System.out.println("Number of Capitals characters : "+iRet);
    }
}
