import java.io.*;

class program658{ 
    public static void main(String A[]) 
    { 
        try{
            File fobj = new File("Demo.txt");
            
            if(fobj.exists()){
                System.out.println("File already exists");
            }
            else{
                fobj.createNewFile();
                System.out.println("File gets successfully created");
            }       
        }
        catch(IOException iobj){
            System.out.println(iobj);
        }
        catch(Exception eobj){
            System.out.println(eobj);
        }  
    }
}
