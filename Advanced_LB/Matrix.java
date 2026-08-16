package Marvellous;

import java.util.*;

public class Matrix{
    protected int Arr[][];
    protected int iRow;
    protected int iCol;

    public Matrix(int iRow,int iCol){
        Arr = new int[iRow][iCol]; 

        this.iRow = iRow;
        this.iCol = iCol;

        System.out.println("Inside Matrix Constructor");
    }

    public void Accept(){
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the elements of matrix : ");        

        for(int i=0;i<iRow;i++){
            for(int j=0;j<iCol;j++){
                Arr[i][j] = sobj.nextInt();
            }
        }

        sobj.close();
    }

    public void Display(){
        System.out.println("Elements of matrix : ");        

        for(int i=0;i<iRow;i++){
            for(int j=0;j<iCol;j++){
                System.out.print( Arr[i][j] + "\t"); 
            }
            System.out.println();        
        }
    }
}
