import java.io.*;
import java.util.*;

class program727 {
    public static void main(String A[]) throws Exception
    {
        Scanner sobj = new Scanner(System.in);

        int iRet = 0;
        int Size = 0;
        int i=0,j=0;

        String FolderName = null;
        String PackFileName = null;
        String header = "";

        byte Buffer[] = new byte[1024];
        byte bHeader[] = null;

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

            for(i=0;i<fArr.length;i++){
                fiobj = new FileInputStream(fArr[i]);

                header = header + fArr[i].getName();
                header = header + " ";
                header = header + fArr[i].length();

                Size = 100-header.length();

                for(j=1;j<=Size;j++){
                    header = header + " ";
                }

                bHeader = header.getBytes();

                // Write file name & size

                foobj.write(bHeader);
                

                // loop to read from fiobj & write into foobj

                /*  while((iRet = fiobj.read(Buffer)) != -1){
                        foobj.write(Buffer,0,iRet);
                    }
                */

                fiobj.close();
                header = "";
            }
            foobj.close();
        }
        else{
            System.out.println("There is no such folder");
        }
        sobj.close();
    }
}
