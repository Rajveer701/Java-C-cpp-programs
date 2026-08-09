import java.util.*;
import java.io.*;

public class program700 {
    public static void main(String args[]){
        String header = "Marvellous";

        System.out.println(header);

        header.replaceAll("l", "L");       // Issue

        System.out.println(header);
    }
}
