import java.util.*;

class program783{
    public static void main(String A[]){
        HashMap <String,Integer> hobj = new HashMap<String,Integer>();

        Scanner sobj = new Scanner(System.in);
        
        System.out.println("Enter string : ");
        String str = sobj.nextLine();

        str = str.trim();

        str = str.replaceAll("\\s+", " ");

        String Tokens[] = str.split(" ");

        for(String s : Tokens){
            if(hobj.containsKey(s)){
                hobj.put(s,hobj.get(s)+1);
            }
            else{
                hobj.put(s,1);
            }
        }

        int iMax = 0;
        String temp = null;

        for(String sVal : hobj.keySet()){
            if(hobj.get(sVal) > iMax){
                iMax = hobj.get(sVal);
                temp = sVal;
            }
        }

        System.out.println(temp + " is the most occuring word with frequency " + iMax);

        sobj.close();
    }
}