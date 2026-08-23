import java.io.*;
import java.net.*;

class program924 {
    public static void main(String A[]){
        try
        {
            ServerSocket serversocket = new ServerSocket(5500);

            System.out.println("-------------------------------------------------------");
            System.out.println("--------------------Server Started---------------------");
            System.out.println("-------------------------------------------------------");

            // Loop for multiple client requests
            while(true){                
                System.out.println("Server is waiting for client request");

                Socket clientSocket = serversocket.accept();

                System.out.println("Client connected successfully");

                // Thread gets created for client 
                Thread t = new Thread(() -> HandleClientRequest(clientSocket));

                t.start();
            }  //End of While
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

            while(true){
                String command = dis.readUTF();

                System.out.println("Command received from Client : " +command);

                String parts[] = command.split(" ");

                String operation = parts[0].toUpperCase();

                if(operation.equals("QUIT")){
                    dos.writeUTF("Disconnected from Server");
                    break;
                }

                if(parts.length != 3){
                    dos.writeUTF("Invalid Command Format");
                    continue;
                }

                double no1 = Double.parseDouble(parts[1]);
                double no2 = Double.parseDouble(parts[2]);

                double result = 0.0;

                if(operation.equals("ADD")){
                    result = no1 + no2;

                    dos.writeUTF("Result is : "+result);
                }

                else if(operation.equals("SUB")){
                    result = no1 - no2;

                    dos.writeUTF("Result is : "+result);
                }
                else{
                    dos.writeUTF("Invalid operation");
                }
            }   // End of while

            socket.close();

            System.out.println("Client Disconnected");
        }
        catch(Exception e){
            System.out.println("Exception Occured : "+e);
        }
    }

}   // End of Class
