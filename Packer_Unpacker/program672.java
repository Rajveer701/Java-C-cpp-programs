import java.io.*;
import java.util.*;

class program672{ 
    public static void main(String A[])
    {
        String Fname = null;
        File fobj = null;
        Scanner sobj = new Scanner(System.in);

        FileOutputStream foobj = null;

        System.out.println("Enter file name : ");
        Fname = sobj.nextLine();
        
        fobj = new File(Fname);

        foobj = new FileOutputStream(fobj);

        String Data = "Marvellous Infosystems";

        if(fobj.exists()){
            foobj.write(Data);          // Errror
        }
        else{
            System.out.println("There is no such file");
        }

    }
}
