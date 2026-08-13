// Input : my name is eminem
// Output : My Name Is Eminem

// Input : my Name is EminEm
// Output : My Name Is Eminem

import java.util.*;

class program740{
    public static void main(String A[]){
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter string : ");
        String str = sobj.nextLine();

        str = str.trim();

        str = str.replaceAll("\\s+"," ");

        str = str.toLowerCase();

        System.out.println("Updated String : " +str);
    }
}