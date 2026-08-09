import java.io.*;
import java.util.*;

class program723{
    public static void main(String A[]) throws Exception
    {
        Scanner sobj = new Scanner(System.in);

        int iRet = 0;

        String FolderName = null;
        String PackFileName = null;
        String header = null;

        FileOutputStream foobj = null;
        FileInputStream fiobj = null;

        System.out.println("Enter folder name : ");
        FolderName = sobj.nextLine();

        System.out.println("Enter the name of packed file : ");
        PackFileName = sobj.nextLine();

        File fobjfolder = new File(FolderName);

        if((fobjfolder.exists()) && (fobjfolder.isDirectory())){
            System.out.println("Folder Exists");

            File fobjpack = new File(PackFileName);
            fobjpack.createNewFile();       // PackFile gets created

            foobj = new FileOutputStream(fobjpack);

            File fArr[] = fobjfolder.listFiles();

            System.out.println("Number of files in folder : " + fArr.length);

            byte Buffer[] = new byte[1024];

            for(int i=0;i<fArr.length;i++){
                fiobj = new FileInputStream(fArr[i]);

                System.out.println(fArr[i].getName());
                System.out.println(fArr[i].length());

                // Write file name & size
                

                // loop to read from fiobj & write into foobj

                /*  while((iRet = fiobj.read(Buffer)) != -1){
                        foobj.write(Buffer,0,iRet);
                    }
                */

                fiobj.close();
            }
            foobj.close();
        }
        else{
            System.out.println("There is no such folder");
        }
        sobj.close();
    }
}
