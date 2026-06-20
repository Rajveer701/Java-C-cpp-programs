/*
    iRow=4
    iCol=4
                ij
    A B C D     11 12 13 14 
    A B C D     21 22 23 24 
    A B C D     31 32 33 34
    A B C D     41 42 43 44
    
*/

import java.util.*;

class Pattern{
    public void Display(int iRow,int iCol){
        int i=0,j=0;
        char ch = '\0';
        for(i=1;i<=iRow;i++){
            for(j=1,ch = 'A';j<=iCol;j++){
                System.out.print(ch + "\t");
                ch++;
            }
            
            System.out.println();
        }
    }
}

class program203{
    public static void main(String A[]){
        Scanner sobj = new Scanner(System.in);
        int iValue1 = 0,iValue2 = 0;

        System.out.println("Enter the number of rows : ");
        iValue1 = sobj.nextInt();

        System.out.println("Enter the number of columns : ");
        iValue2 = sobj.nextInt();

        Pattern pobj = new Pattern();

        pobj.Display(iValue1, iValue2);
    }
}