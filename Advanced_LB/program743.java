// Input : my name is eminem
// Output : My Name Is Eminem

// Input : my Name is EminEm
// Output : My Name Is Eminem

import java.util.*;

class program743{
    public static void main(String A[]){
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter string : ");
        String str = sobj.nextLine();

        str = str.trim();

        str = str.replaceAll("\\s+"," ");

        str = str.toLowerCase();

        char Arr[] = str.toCharArray();

        if(Arr[0] >= 'a' && Arr[0] <= 'z'){
            Arr[0] = (char)(Arr[0] - 32);
        }

        for(int i=0;i<Arr.length;i++){
            if(Arr[i] == ' '){
                if(Arr[i+1] >= 'a' && Arr[i] <= 'z'){
                    Arr[i+1] = (char)(Arr[i+1] - 32);
                }
            }
        }

        System.out.println("Updated String : " + new String(Arr));
    }
}