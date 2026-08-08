import java.io.*;
import java.util.*;

class program671{ 
    public static void main(String A[])
    {
        String Fname = null;
        File fobj = null;
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter file name : ");
        Fname = sobj.nextLine();
        
        fobj = new File(Fname);

        if(fobj.exists()){
            System.out.println("File Name : "+fobj.getName());
            System.out.println("Absolute Path : "+fobj.getAbsolutePath());
            System.out.println("File size : "+fobj.length());
        }
        else{
            System.out.println("There is no such file");
        }

    }
}
