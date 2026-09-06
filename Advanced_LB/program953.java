// java program952.java programming

import java.util.*;

class program953 {
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
        
        for(char ch : frequency.keySet()){
            if(frequency.get(ch) == 1){
                System.out.println("First non-repeating character : " +ch);
                break;
            }
        }
    }
}
