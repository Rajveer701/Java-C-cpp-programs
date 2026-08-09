import java.io.*;
import java.util.*;

class program693{
    public static void main(String A[]) throws Exception
    {
        Scanner sobj = new Scanner(System.in);

        int iRet = 0;

        String FolderName = null;
        String PackFileName = null;

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

            for(int i=0;i<fArr.length;i++){
                fiobj = new FileInputStream(fArr[i]);

                // Write file name & size
                String Header = "--------------------------------\n";
                Header += "File Name : " + fArr[i].getName() + "\n";
                Header += "File Size : " + fArr[i].length() + "\n";
                Header += "--------------------------------\n";

                foobj.write(Header.getBytes());

                foobj.write("File Content : ".getBytes());

                // loop to read from fiobj & write into foobj

                byte Buffer[] = new byte[1024];
                 
                while((iRet = fiobj.read(Buffer)) != -1){
                    foobj.write(Buffer,0,iRet);
                }
                foobj.write("\n\n".getBytes());
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
