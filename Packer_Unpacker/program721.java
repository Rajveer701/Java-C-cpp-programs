import java.util.*;
import java.io.*;

public class program721 {
    public static void main(String args[]){
        String header = "A.txt 10";

        System.out.println("Actual length : " +header.length());    // 8

        System.out.println("Number of white spaces needed : " +(100 - header.length()));

        int size = 100 - header.length();

        for(int i=1;i<=size;i++){
            header = header + " ";
        }

        System.out.println("Updated header length : " +header.length());
    }
}
