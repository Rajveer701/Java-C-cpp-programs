// java program954.java programming

import java.util.*;

class program955 {
    public static void main(String A[]){
        LinkedHashMap <Character,Integer> frequency = new LinkedHashMap<Character,Integer>();

        if(A.length != 1){
            System.out.println("Invalid number of arguments");
            return;
        }

        String str = A[0];

        for(char ch : str.toCharArray()){
            frequency.put(ch, frequency.getOrDefault(ch,0)+1);
        }
        
        for(Map.Entry<Character,Integer> eobj : frequency.entrySet()){
            if(eobj.getValue() == 1){
                System.out.println(eobj.getKey());
                break;
            }
        }
    }
}
