// Input : my name is eminem
// Output : ym eman si menime

import java.util.*;

class program746{
    public static void main(String A[]){
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter string : ");
        String str = sobj.nextLine();

        str = str.trim();

        str = str.replaceAll("\\s+", " ");

        String Tokens[] = str.split(" ");

        StringBuffer sb = null;
        StringBuffer FinalStr = new StringBuffer(""); 

        for(int i=0;i<Tokens.length;i++){
            sb = new StringBuffer(Tokens[i]);
            FinalStr = FinalStr.append(sb.reverse() + " ");
        }
        System.out.println(FinalStr);
    }
}