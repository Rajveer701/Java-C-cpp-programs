import java.io.*;
import java.net.*;

class program930 {
    public static int ClientCount = 1;
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


    // Request Handle Client for each client request
    public static void HandleClientRequest(Socket socket){
        System.out.println("New thread gets created for Client no : " +ClientCount);
        ClientCount++;
        
        try{
            DataInputStream dis = new DataInputStream(socket.getInputStream());
            DataOutputStream dos = new DataOutputStream(socket.getOutputStream());

            dos.writeUTF("Connected to Server");

            while(true){
                // Read command from client
                
                String command = dis.readUTF();

                System.out.println("Command received from Client : " +command);

                String parts[] = command.split(" ");

                String operation = parts[0].toUpperCase();

                if(operation.equals("QUIT")){
                    dos.writeUTF("Disconnected from Server");

                    ClientCount--;
                    
                    break;
                }

                if(operation.equals("GET")){
                    if(parts.length != 2){
                        dos.writeUTF("Usage : GET <FileName>");
                        
                        continue;
                    }
                }
                else if(operation.equals("PUT")){
                    if(parts.length != 2){
                        dos.writeUTF("Usage : PUT <FileName>");
                        
                        continue;
                    }
                }
                else if(operation.equals("INFO")){
                    if(parts.length != 2){
                        dos.writeUTF("Usage : INFO <FileName>");
                        
                        continue;
                    }

                    File file = new File(parts[1]);

                    if(file.exists()){
                        String info = "";

                        info = info + "File Name : " + file.getName() + "\n";

                        info = info + "File Size : " + file.length() + "\n";

                        info = info + "Readable : " + file.canRead() + "\n";

                        info = info + "Writeable : " + file.canWrite() + "\n";

                        dos.writeUTF(info);
                    }
                    else{
                        dos.writeUTF("File does not exist");
                    }

                }
                // SIZE demo.txt
                else if(operation.equals("SIZE")){
                    if(parts.length != 2){
                        dos.writeUTF("Usage : SIZE <FileName>");
                        
                        continue;
                    }

                    File file = new File(parts[1]);

                    if(file.exists() && file.isFile()){
                        dos.writeUTF("File Size is : " +file.length() + " bytes");
                    }
                    else{
                        dos.writeUTF("File does not exist");
                    }
                }
                else if(operation.equals("EXISTS")){
                    if(parts.length != 2){
                        dos.writeUTF("Usage : EXISTS <FileName>");
                        
                        continue;
                    }

                    File file = new File(parts[1]);

                    if(file.exists()){
                        dos.writeUTF("File exists");
                    }
                    else{
                        dos.writeUTF("File does not exist");
                    }

                }

                // RENAME demo.txt demoX.txt
                else if(operation.equals("RENAME")){
                    if(parts.length != 3){
                        dos.writeUTF("Usage : RENAME <OldFileName><NewFileName>");
                        
                        continue;
                    }

                    File oldfile = new File(parts[1]);

                    File newfile = new File(parts[2]);

                    if(oldfile.exists() == false){
                        dos.writeUTF("Source File does not exist");

                        continue;
                    }

                    if(oldfile.renameTo(newfile)){
                        dos.writeUTF("File renamed successfully");
                    }
                    else{
                        dos.writeUTF("Unable to rename file");
                    }
                }
                else if(operation.equals("DELETE")){
                    if(parts.length != 2){
                        dos.writeUTF("Usage : DELETE <FileName>");

                        continue;
                    }

                    File file = new File(parts[1]);

                    if(file.exists() == false){
                        dos.writeUTF("There is no such file");

                        continue;
                    }
                    
                    if(file.delete()){
                        dos.writeUTF("File deleted successfully");
                    }
                    else{
                        dos.writeUTF("Unable to delete the File");
                    }
                }
                else if(operation.equals("LIST")){
                    if(parts.length != 1){
                        dos.writeUTF("Usage : LIST");
                        
                        continue;
                    }

                    File folder = new File(".");    // Current directory obj

                    File files[] = folder.listFiles();

                    String result = "";

                    if(files != null){
                        for(File f : files){
                            if(f.isFile()){
                                result = result + f.getName() + "\n";
                            }
                        }
                    }
                    if(result.length() == 0){
                        result = "No files available";
                    }

                    dos.writeUTF(result);
                }
                else{
                    dos.writeUTF("Invalid operation");
                }
            }   // End of while

            socket.close();
            dis.close();
            dos.close();

            System.out.println("Client Disconnected");
        }   // End of try
        catch(Exception e){
            System.out.println("Exception Occured : "+e);
        }
    }   // End of HandleClientRequest()

}   // End of Class
