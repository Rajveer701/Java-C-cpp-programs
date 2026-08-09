import java.util.*;
import java.io.*;

public class program711 {
    public static void main(String args[]){
        String header = "India  is  my  country";

        String Arr[] = header.split(" ");

        System.out.println("Number of words : " +Arr.length);

        for(int i=0;i<Arr.length;i++){
            System.out.println(Arr[i]);
        }
    }
}
