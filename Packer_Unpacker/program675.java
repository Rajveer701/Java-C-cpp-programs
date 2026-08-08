import java.io.*;
import java.util.*;

class program675{ 
    public static void main(String A[])
    {
        String Data = "Marvellous Infosystems";

        byte Arr[] = Data.getBytes();       // str to byte conversion

        for(int i=0; i<Arr.length; i++){
            System.out.print((char)Arr[i]);
        }
    }
}
