import java.util.*;

class HashMapX{
    public static void main(String[] args) {

        HashMap<Integer, String> map = new HashMap<>(); 
        
        map.put(1, "Marvellous"); 
        map.put(2, "Infosystems"); 
        System.out.println("Value at key 1: + map.get(1)");

        for (Map.Entry<Integer, String> entry : map.entrySet()){ 
            System.out.println(entry.getKey() + "->" + entry.getValue());
        }
    }
}