import java.util.*;
import java.io.*;

public class program704 {
    public static void main(String args[]){
        String header = "    India   is   my   country    ";

        System.out.println(header.length());

        header = header.trim();     

        System.out.println(header.length());

        header = header.replaceAll("  ", " ");

        System.out.println(header.length());

        header = header.replaceAll("   ", " ");

        System.out.println(header.length());
    }
}
