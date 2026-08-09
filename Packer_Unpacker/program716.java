import java.util.*;
import java.io.*;

class StringX{
    int CountWords(String str){
        str = str.trim();

        str = str.replaceAll("\\s+", " ");

        String Tokens[] = str.split(" ");

        return Tokens.length;
    }

    void DisplayWords(String str){
        str = str.trim();

        str = str.replaceAll("\\s+", " ");

        String Tokens[] = str.split(" ");

        for(int i=0;i<Tokens.length;i++){
            System.out.println(Tokens[i] + " : " +Tokens[i].length());
        }
    }

    void LargestWord(String str){
        str = str.trim();

        str = str.replaceAll("\\s+", " ");

        String Tokens[] = str.split(" ");

        int iMax = 0;

        for(int i=0;i<Tokens.length;i++){
            if(Tokens[i].length() > iMax){
                iMax = Tokens[i].length();
            }
        }

        System.out.println("Largest Word length : " +iMax);

        for(int i=0;i<Tokens.length;i++){
            if(Tokens[i].length() == iMax){
                System.out.println("Largest Word : " +Tokens[i]);
            }
        }
    }


}

public class program716 {
    public static void main(String args[]){
        StringX strobj = new StringX();
        int iRet = 0;

        Scanner sobj = new Scanner(System.in);

        String str = null;

        System.out.println("Enter string : ");
        str = sobj.nextLine();

        iRet = strobj.CountWords(str);
        System.out.println("Number of words : " +iRet);

        strobj.DisplayWords(str);

        strobj.LargestWord(str);
    }
}
