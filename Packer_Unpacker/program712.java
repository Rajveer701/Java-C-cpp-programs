import java.util.*;
import java.io.*;

public class program712 {
    public static void main(String args[]){
        String header = "India  is  my  country";

        header = header.trim();

        header = header.replaceAll("\\s+", " ");

        String Arr[] = header.split(" ");

        System.out.println("Number of words : " +Arr.length);

        for(int i=0;i<Arr.length;i++){
            System.out.println(Arr[i]);
        }
    }
}
