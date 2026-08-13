import java.util.*;

class program755{
    public static void main(String A[]){
        int i = 0;

        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter string : ");
        String str = sobj.nextLine();

        str = str.trim();

        str = str.replaceAll("\\s+", " ");

        str = str.toLowerCase();

        char Arr[] = str.toCharArray();

        int Freq[] = new int[26];

        // a    b   c   d
        // 97  98   99  100
        // 0    1   2   3
        for(i=0;i<Arr.length;i++){
            if(Arr[i] >= 'a' && Arr[i] <= 'z'){
                Freq[(int)Arr[i]-97]++;
            }
        }

        int iMax = 0;
        char ch = '\0';

        for(i=0;i<Freq.length;i++){
            if(Freq[i]>iMax){
                iMax = Freq[i];
                ch = (char)(i + 97);
            }  
        }
        System.out.println("Letter with highest frequency : " +ch + " with frequency : " + iMax);
    }
}