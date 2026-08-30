import java.util.*;

// java program950.java 10 11

class program950{
    public static void main(String A[]){
        int ans = 0;
        if(A.length != 2){
            System.out.println("Invalid number of argumnets\n");
            return;
        }
        ans = Integer.parseInt(A[0])+ Integer.parseInt(A[1]);   
        
        System.out.println("Addition is : " +ans);
    }
}
