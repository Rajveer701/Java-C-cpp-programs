import java.io.*;
import java.util.*;

class program684{
    public static void main(String A[]) throws Exception
    {
        String FnameSrc = null;
        String FnameDest = null;
        File fobjsrc = null;
        File fobjdest = null;
        int iRet = 0;
        Scanner sobj = new Scanner(System.in);

        FileInputStream fiobj = null;
        FileOutputStream foobj = null;

        System.out.println("Enter source file name : ");
        FnameSrc = sobj.nextLine();

        System.out.println("Enter destination file name : ");
        FnameDest = sobj.nextLine();
        
        fobjsrc = new File(FnameSrc);
        fobjdest = new File(FnameDest);

        fiobj = new FileInputStream(fobjsrc);
        foobj = new FileOutputStream(fobjdest);

        fobjdest.createNewFile();

        byte Buffer[] = new byte[100];

        if(fobjsrc.exists()){
            String str = null;

            while((iRet = fiobj.read(Buffer)) != -1){
                foobj.write(Buffer,0,iRet);
            }
            fiobj.close();
            foobj.close();
        }
        else{
            System.out.println("There is no such file");
        }

    }
}
