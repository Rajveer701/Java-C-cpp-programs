import java.util.*;

class StringX{
    public String updateString(String str){
        char Arr[] = str.toCharArray();
        int i = 0;

        for(i=0;i<Arr.length;i++){
            if(Arr[i]=='A' || Arr[i]=='a'){
                Arr[i] = '_';
            }
        }
        return new String(Arr);
    }
}

public class program279{
    public static void main(String A[]){
        Scanner sobj = new Scanner(System.in);
        String data = null;
        String sRet = null;

        StringX strobj = new StringX();

        System.out.println("Enter string : ");

        data = sobj.nextLine();

        sRet = strobj.updateString(data);

        System.out.println("Updated String : "+sRet);
    }
}
