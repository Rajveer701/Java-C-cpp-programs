import java.util.*;
import java.io.*;

public class program722 {
    public static void main(String args[]){
        String header = "hello.txt 1078";

        System.out.println("Actual length : " +header.length());    // 8

        System.out.println("Number of white spaces needed : " +(100 - header.length()));

        int size = 100 - header.length();

        for(int i=1;i<=size;i++){
            header = header + " ";
        }

        System.out.println("Updated header length : " +header.length());
        System.out.println("Updated header : " +header);
    }
}
