import java.io.*;
import java.net.*;
import java.util.*;

class program919{
    public static void main(String A[]){
        try
        {
            System.out.println("-------------------------------------------------------");
            System.out.println("--------------------Client Started---------------------");
            System.out.println("-------------------------------------------------------");

            Socket socket = new Socket(
                                        "127.0.0.1",
                                        5500
                                    );

            System.out.println("Connection with Server is successful");
        }
        catch(Exception e){
            System.out.println("Exception Occured : "+e);
        }
    }
}
