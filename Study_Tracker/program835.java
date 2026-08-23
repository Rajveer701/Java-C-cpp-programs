import java.util.*;

class program835{
    public static void main(String A[]) throws Exception
    {
        Scanner sobj = new Scanner(System.in);

        ArrayList <Integer>aobj = new ArrayList<Integer>();

        aobj.add(11);
        aobj.add(21);
        aobj.add(51);
        aobj.add(101);
        aobj.add(51);
        aobj.remove(4);
        aobj.remove(3);

        for(int No : aobj){
            System.out.println(No);
        }

        aobj.clear();

        System.out.println(aobj);
    }  
}
