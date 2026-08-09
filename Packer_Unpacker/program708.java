import java.util.*;
import java.io.*;

public class program708 {
    public static void main(String args[]){
        Scanner sobj = new Scanner(System.in);

        String str = null;

        System.out.println("Enter string : ");
        str = sobj.nextLine();

        System.out.println("Input string : "+str+" having length : "+str.length());

        str = str.trim();

        System.out.println("Input string : "+str+" having length : "+str.length());

        str = str.replaceAll("\\s+", " ");       // \\s+ -> more than 1

        System.out.println("Input string : "+str+" having length : "+str.length());
    }
}
