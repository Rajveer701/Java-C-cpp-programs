import java.util.*;

class StringX{
    public int CountDigits(String str){
        int iCount = 0;
        int i = 0;

        char Arr[] = str.toCharArray();

        for(i=0;i<Arr.length;i++){
            if(Arr[i]>='0' && Arr[i]<='9'){
                iCount++;
            }
        }

        return iCount;
    }

    public int CountCapital(String str){
        int iCount = 0;
        int i = 0;

        char Arr[] = str.toCharArray();

        for(i=0;i<Arr.length;i++){
            if(Arr[i]>='A' && Arr[i]<='Z'){
                iCount++;
            }
        }

        return iCount;
    }

    public int CountSmall(String str){
        int iCount = 0;
        int i = 0;

        char Arr[] = str.toCharArray();

        for(i=0;i<Arr.length;i++){
            if(Arr[i]>='a' && Arr[i]<='z'){
                iCount++;
            }
        }

        return iCount;
    }
}

public class program273{
    public static void main(String A[]){
        Scanner sobj = new Scanner(System.in);
        String data = null;
        int iRet = 0;

        StringX strobj = new StringX();

        System.out.println("Enter string : ");

        data = sobj.nextLine();

        iRet = strobj.CountCapital(data);

        System.out.println("Number of Capitals characters : "+iRet);

        iRet = strobj.CountSmall(data);

        System.out.println("Number of Small characters : "+iRet);

        iRet = strobj.CountDigits(data);

        System.out.println("Number of Digits : "+iRet);
    }
}
