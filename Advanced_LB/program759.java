// Check if 2 strings are Anagram

import java.util.*;

class program759{

    public static boolean CheckAnagram(String str1,String str2){
        int i = 0;
        boolean bFlag = true;

        if(str1.length() != str2.length()) return false;

        str1 = str1.trim();
        str2 = str2.trim();

        str1 = str1.replaceAll("\\s+", " ");
        str2 = str2.replaceAll("\\s+", " ");

        str1 = str1.toLowerCase();
        str2 = str2.toLowerCase();

        char Arr[] = str1.toCharArray();
        char Brr[] = str2.toCharArray();

        int Freq1[] = new int[26];
        int Freq2[] = new int[26];

        for(i=0;i<Arr.length;i++){
            if(Arr[i] >= 'a' && Arr[i] <= 'z' && Brr[i] >= 'a' && Brr[i] <= 'z'){
                Freq1[(int)Arr[i]-97]++;
            }
            if(Brr[i] >= 'a' && Brr[i] <= 'z'){
                Freq2[(int)Brr[i]-97]++;
            }
        }

        for(i=0;i<Freq1.length;i++){
            if(Freq1[i] != Freq2[i]){
                bFlag = false;
                break;
            }
        }

        return bFlag;
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