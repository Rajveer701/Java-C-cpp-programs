import java.util.*;

class LinkedListX{
    public static void main(String[] args){

        LinkedList<String> list = new LinkedList<>();
        
        list.add("Marvellous");
        list.addFirst("Ganesh");
        list.addLast("Saraswati");

        System.out.println("List:" + list);

        list.removeFirst();

        System.out.println("After Removal:  " +list);
    }    
}