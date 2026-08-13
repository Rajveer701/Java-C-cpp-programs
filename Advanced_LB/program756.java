// Check if 2 strings are Anagram

import java.util.*;

class program756{

    public static boolean CheckAnagram(String str1,String str2){
        int i = 0;
        char Arr1[] = str1.toCharArray();
        char Arr2[] = str2.toCharArray();

        int Freq1[] = new int[26];
        int Freq2[] = new int[26];

        // a    b   c   d
        // 97  98   99  100
        // 0    1   2   3
        for(i=0;i<Arr1.length;i++){
            if(Arr1[i] >= 'a' && Arr1[i] <= 'z'){
                Freq1[(int)Arr1[i]-97]++;
            }
        }

        for(i=0;i<Arr2.length;i++){
            if(Arr2[i] >= 'a' && Arr2[i] <= 'z'){
                Freq2[(int)Arr2[i]-97]++;
            }
        }

        return true;
    }

    public static void main(String A[]){
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter first string : ");
        String str1 = sobj.nextLine();

        System.out.println("Enter second string : ");
        String str2 = sobj.nextLine();

        boolean bRet = false;

        bRet = CheckAnagram(str1,str2);

        if(bRet == true){
            System.out.println("Strings are Anagram");
        }
        else{
            System.out.println("Strings are not Anagram");
        }
    }
}