import java.io.*;
import java.net.*;

class program921 {
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

            // Thread gets created for client 
            Thread t = new Thread(() -> HandleClientRequest(clientSocket));

            t.start();
        }
        catch(Exception e){
            System.out.println("Exception Occured : "+e);
        }
    }   // End of Main

    public static void HandleClientRequest(Socket socket){
        try{
            DataInputStream dis = new DataInputStream(socket.getInputStream());
            DataOutputStream dos = new DataOutputStream(socket.getOutputStream());

            dos.writeUTF("Connected to Server");
        }
        catch(Exception e){
            System.out.println("Exception Occured : "+e);
        }
    }

}   // End of Class
