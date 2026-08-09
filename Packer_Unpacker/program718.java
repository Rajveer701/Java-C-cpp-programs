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
        String temp = null;

        for(int i=0;i<Tokens.length;i++){
            if(Tokens[i].length() > iMax){
                iMax = Tokens[i].length();
                temp = Tokens[i];
            }
        }

        System.out.println("Largest Word length : " +iMax);
        System.out.println("Largest Word : " +temp);
    }

    int PatternMatch(String str,String word){
        int iCount = 0;

        str = str.trim();

        str = str.replaceAll("\\s+", " ");

        String Tokens[] = str.split(" ");

        for(int i=0;i<Tokens.length;i++){
            if(word.equals(Tokens[i])){
                iCount++;
            }
        }

        return iCount;
    }
}

public class program718 {
    public static void main(String args[]){
        StringX strobj = new StringX();
        int iRet = 0;

        Scanner sobj = new Scanner(System.in);

        String str = null;
        String word = null;

        System.out.println("Enter string : ");
        str = sobj.nextLine();

        System.out.println("Enter word : ");
        word = sobj.nextLine();

        iRet = strobj.CountWords(str);
        System.out.println("Number of words : " +iRet);

        strobj.DisplayWords(str);

        strobj.LargestWord(str);

        iRet = strobj.PatternMatch(str, word);
        System.out.println("Frequency of matched words : " +iRet);
    }
}
