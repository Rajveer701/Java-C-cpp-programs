import java.util.*;
import java.io.*;

public class program701 {
    public static void main(String args[]){
        String header = "Marvellous";

        System.out.println(header);

        header = header.replaceAll("l", "L");       // Issue resolved

        System.out.println(header);
    }
}
