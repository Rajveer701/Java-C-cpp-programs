import java.util.*;

// java program949.java 10 11

class program949{
    public static void main(String A[]){
        int ans = 0;
        if(A.length != 2){
            System.out.println("Invalid number of argumnets\n");
            return;
        }
        // ans = A[0] + A[1];   // Error
        
        System.out.println("Addition is : " +(A[0] + A[1]));
    }
}
