import java.io.*;
import java.net.*;

class program918 {
    public static void main(String A[]){
        try
        {
            ServerSocket serversocket = new ServerSocket(5500);

            System.out.println("-------------------------------------------------------");
            System.out.println("--------------------Server Started---------------------");
            System.out.println("-------------------------------------------------------");

            System.out.println("Server is waiting for client request");

            Socket clientSocket = serversocket.accept();

            System.out.println("Client connected successfully");
        }
        catch(Exception e){
            System.out.println("Exception Occured : "+e);
        }
    }
}
