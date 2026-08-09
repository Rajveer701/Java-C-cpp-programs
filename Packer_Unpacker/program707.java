import java.util.*;
import java.io.*;

public class program707 {
    public static void main(String args[]){
        Scanner sobj = new Scanner(System.in);

        String str = null;

        System.out.println("Enter string : ");
        str = sobj.nextLine();

        System.out.println("Input string : "+str+" having length : "+str.length());

        str = str.trim();

        System.out.println("Input string : "+str+" having length : "+str.length());

        str = str.replaceAll(" ", "");       

        System.out.println("Input string : "+str+" having length : "+str.length());
    }
}
